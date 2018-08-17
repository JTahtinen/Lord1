#include "mesh.h"
#include "vertexbuffer.h"
#include <iostream>

namespace Lord1 { namespace graphics {

	VertexBufferLayout Mesh::default2DLayout;
	VertexBufferLayout Mesh::defaultColorLayout;

	Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
	{
		using namespace math;
		//indices->bind();
		_vao.setIndices(indices);
		unsigned int count = vertices.size();
		Vec4* positions = new Vec4[count];
		Vec4* colors = new Vec4[count];

		for (unsigned int i = 0; i < count; ++i)
		{
			positions[i] = vertices[i].pos;
			colors[i] = vertices[i].color;
		}

		VertexBuffer* positionBuffer = VertexBuffer::genVertexBuffer(positions, count * sizeof(Vec4), &Mesh::default2DLayout);
		VertexBuffer* colorBuffer = VertexBuffer::genVertexBuffer(colors, count * sizeof(Vec4), &Mesh::defaultColorLayout);
		
		_vao.push(positionBuffer);
		_vao.push(colorBuffer);

		delete positions;
		delete colors;
	}

	void VertexData::push(const Vertex& vertex)
	{
		_positions.push_back(vertex.pos);
		_colors.push_back(vertex.color);
	}
	void VertexData::push(const std::vector<Vertex>& vertices)
	{
		for (const Vertex& vertex : vertices)
		{
			push(vertex);
		}
	}
}}