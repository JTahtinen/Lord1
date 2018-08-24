#include "simple2drenderer.h"
#include "../../defs.h"
#include "../staticsprite.h"
namespace lord { namespace graphics {

	void Simple2DRenderer::submit(Renderable2D* renderable)
	{
		if (renderable)
		_renderables.push_back((StaticSprite*)renderable);
	}

	void Simple2DRenderer::flush()
	{
		for (StaticSprite* renderable : _renderables)
		{
			renderable->vao.bind();
			Shader* shader = renderable->shader;
			shader->bind();
			Matrix4f model = Matrix4f::translate(renderable->vertex.position);
			shader->setUniformMat4("u_mvp", _projection * model);
			const IndexBuffer* ibo = renderable->vao.getIndexBuffer();
			ibo->bind();
			
			GLCALL(glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, NULL));
			_renderables.pop_front();
		}
		glBindVertexArray(0);
	}

}}