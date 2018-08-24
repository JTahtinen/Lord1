#include "renderable2d.h"

namespace lord { namespace graphics {

	Renderable2D::Renderable2D(const math::Vec2& position, const math::Vec2& size)
		: vertex({ math::Vec3(position.x, position.y, 0), math::Vec4(0.7f, 0.02f, 0.2f, 1.0f) })
		, size(size)
	{
	}

}}