#pragma once
#include "../math/math.h"
#include "buffers/vertexarray.h"
#include "vertex.h"
#include "shader.h"

namespace lord { namespace graphics {

	using namespace math;
	class StaticSprite
	{
	public:
		Vertex vertex;
		Vec2 size;
		Shader* shader;
		VertexArray vao;
	public:
		StaticSprite(const Vec2& position, const Vec2& size, Shader* shader);
	};

}}