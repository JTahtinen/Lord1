#include "batchrenderer2d.h"
#include "../../defs.h"
namespace lord { namespace graphics {

	BatchRenderer2D::BatchRenderer2D(const Window& win)
		: Renderer2D(win)
		, _buffer(nullptr)
		, _numIndices(0)
	{
		GLCALL(glGenVertexArrays(1, &_vao));
		GLCALL(glBindVertexArray(_vao));
		GLCALL(glGenBuffers(1, &_vbo));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _vbo));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW));
		GLCALL(glEnableVertexAttribArray(SHADER_POSITION_INDEX));
		GLCALL(glEnableVertexAttribArray(SHADER_COLOR_INDEX));
		GLCALL(glVertexAttribPointer(SHADER_POSITION_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)0));
		GLCALL(glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)sizeof(math::Vec3)));

		std::vector<unsigned int> indices;
		indices.reserve(RENDERER_INDICES_SIZE);
		for (unsigned int i = 0; i < RENDERER_MAX_SPRITES; ++i)
		{
			indices.push_back(0 + i * 4);
			indices.push_back(1 + i * 4);
			indices.push_back(2 + i * 4);
			indices.push_back(2 + i * 4);
			indices.push_back(0 + i * 4);
			indices.push_back(3 + i * 4);
		}
		_ibo = new IndexBuffer(indices);
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
		glBindVertexArray(0);
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		glDeleteVertexArrays(1, &_vao);
		_vao = 0;
		_vbo = 0;
		_buffer = nullptr;
		delete _ibo;
		_ibo = nullptr;
	}

	void BatchRenderer2D::begin()
	{
		glBindVertexArray(_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);

		_buffer = (Vertex*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer2D::submit(Renderable2D* renderable)
	{
		using namespace math; 
		const Vec3& pos = renderable->vertex.position;
		const Vec2& size = renderable->size;
		const Vec4& color = renderable->vertex.color;

		_buffer->position = pos;
		_buffer->color = renderable->vertex.color;
		_buffer++;

		_buffer->position = pos + Vec2(0, size.y);
		_buffer->color = color;
		_buffer++;

		_buffer->position = pos + size;
		_buffer->color = color;
		_buffer++;

		_buffer->position = pos + Vec2(size.x, 0);
		_buffer->color =  color;
		_buffer++;
		
		_numIndices += 6;
	}


	void BatchRenderer2D::flush()
	{
		_ibo->bind();
		glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, NULL);
		_ibo->unbind();
		GLCALL(glBindVertexArray(0));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
		_ibo->unbind();
		_numIndices = 0;
	}

	void BatchRenderer2D::end()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
	}
}}