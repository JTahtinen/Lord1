#pragma once
#include "buffers/vertexarray.h"
#include "shader.h"
#include "../math/math.h"
#include "vertex.h"

namespace lord { namespace graphics {
	
	class Renderable2D
	{
	public:
		Vertex vertex;
		math::Vec2 size;
	public:
		Renderable2D(const math::Vec2& position, const math::Vec2& size);
	};

}}