#include "renderable2d.h"

namespace lord { namespace graphics {

	Renderable2D::Renderable2D(const Vec2& position, const Vec2& size, Shader* shader)
		: position(Vec3(position.x, position.y, 0))
		, size(size)
		, shader(shader)
	{
		vao.bind();
		const float data[] {
			0,		0,		0, 1.0f,
			0,		size.y, 0, 1.0f,
			size.x, size.y, 0, 1.0f,
			size.x, 0,		0, 1.0f
		};
		VertexBufferLayout layout;
		layout.push<float>(4);
		Vec4 colors[]
		{
			Vec4(0.7f, 0.02f, 0.2f, 1.0f),
			Vec4(0, 0, 0.4f, 1.0f),
			Vec4(0, 0, 0.2f, 1.0f),
			Vec4(0, 0, 0.0f, 1.0f)
		};
		VertexBufferLayout colorLayout;
		colorLayout.push<float>(4);
		vao.push(VertexBuffer::genVertexBuffer(&data[0], 16 * sizeof(float), &layout));
		vao.push(VertexBuffer::genVertexBuffer(&colors[0], 16 * sizeof(float), &colorLayout));
		std::vector<unsigned int> indices;
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(2);
		indices.push_back(0);
		indices.push_back(3);
		vao.setIndices(indices);

	}

}}