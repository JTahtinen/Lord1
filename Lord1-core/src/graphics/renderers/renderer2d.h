#pragma once
#include "../renderable2d.h"
#include "../../math/mat4.h"
#include "../window.h"
namespace lord { namespace graphics {

class Renderer2D
{
protected:
	math::Matrix4f _projection;
public:
	Renderer2D(const Window& win)
	{
		float aspect = (float)win.getWidth() / (float)win.getHeight();
		_projection = math::Matrix4f::ortho(-1.0f, 1.0f, (1.0f / aspect), -(1.0f / aspect), 0, 200.0f);
	}
	virtual ~Renderer2D() {};
	virtual void submit(Renderable2D* renderable) = 0;
	virtual void flush() = 0;
};

}}