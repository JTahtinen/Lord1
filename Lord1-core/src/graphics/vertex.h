#pragma once
#include "../math/math.h"

namespace lord { namespace graphics {

	class Vertex
	{
	public:
		math::Vec3		position;
		math::Vec4		color;
	public:
		Vertex(const math::Vec3& pos, const math::Vec4& color) : position(pos), color(color) {}
		Vertex(float x, float y, float z, float r, float g, float b, float a)
			: Vertex(math::Vec3(x, y, z), math::Vec4(r, g, b, a)) {}
	};

}}