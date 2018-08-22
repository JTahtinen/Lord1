#pragma once
#include "buffers/vertexarray.h"
#include "shader.h"
#include "../math/math.h"

namespace lord { namespace graphics {

	using namespace math;
class Renderable2D
{
public:
	VertexArray vao;
	Vec3 position;
	Vec2 size;
	Shader* shader;
public:
	Renderable2D(const Vec2& position, const Vec2& size, Shader* shader);
};

}}