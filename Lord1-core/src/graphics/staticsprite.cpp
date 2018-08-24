#include "staticsprite.h"

namespace lord { namespace graphics {

	StaticSprite::StaticSprite(const Vec2& position, const Vec2& size, Shader* shader)
		: vertex({ Vec3(position.x, position.y, 0), Vec4(0.7f, 0.02f, 0.2f, 1.0f) })
		, shader(shader)
	{
		vao.bind();
		const float data[]{
			0,		0,		0,
			0,		size.y, 0,
			size.x, size.y, 0,
			size.x, 0,		0
		};

		const Vec4 colors[]
		{
			vertex.color, 
			vertex.color,
			vertex.color,
			vertex.color
		};
		VertexBufferLayout layout;
		layout.push<float>(3);
		VertexBufferLayout colorLayout;
		colorLayout.push<float>(4);
		vao.push(VertexBuffer::genVertexBuffer(&data[0], 4 * sizeof(Vec3), &layout));
		vao.push(VertexBuffer::genVertexBuffer(&colors[0],  4 * sizeof(Vec4), &colorLayout));
		std::vector<unsigned int> indices;
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(2);
		indices.push_back(0);
		indices.push_back(3);
		vao.setIndices(indices);
		vao.unbind();
	}

}}