#pragma once
#include "buffers/vertexarray.h"
#include "buffers/indexbuffer.h"
#include "../math/vec4.h"
#include "../math/vec2.h"
#include <vector>

namespace lord { namespace graphics {

	class Vertex
	{
	public:
		math::Vec4		pos;
		math::Vec4		color;
	public:
		Vertex(const math::Vec4& pos, const math::Vec4& color) : pos(pos), color(color) {}
		Vertex(float x, float y, float z, float w, float r, float g, float b, float a)
			: Vertex(math::Vec4(x, y, z, w), math::Vec4(r ,g ,b, a)) {}
	};

	class VertexData
	{
		std::vector<math::Vec4>		_positions;
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