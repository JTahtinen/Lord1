#pragma once
#include "buffers/vertexarray.h"
#include "buffers/indexbuffer.h"
#include "../math/vec4.h"
#include "../math/vec2.h"
#include "vertex.h"
#include <vector>

namespace lord { namespace graphics {



	class VertexData
	{
		std::vector<math::Vec3>		_positions;
		std::vector<math::Vec4>		_colors;
	public:
		VertexData() { _positions.reserve(100); _colors.reserve(100); }
		void push(const Vertex& vertex);
		void push(const std::vector<Vertex>& vertices);
	};

	class Mesh
	{
		VertexArray		_vao;
	public:
		Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
		const VertexArray* getVertexArray() const { return &_vao; }
		

	};

}}