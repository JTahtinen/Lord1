#pragma once
#include "renderer2d.h"
#include "../staticsprite.h"
#include <deque>

namespace lord { namespace graphics {

	class Simple2DRenderer : public Renderer2D
	{
		std::deque<StaticSprite*> _renderables;
	public:
		Simple2DRenderer(const Window& win) : Renderer2D(win) {}
		void submit(Renderable2D* renderable) override;
		void flush() override;
	};

}}