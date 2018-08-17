#pragma once
#include <SDL.h>
namespace Lord1 { namespace graphics {

	class Window
	{
		SDL_Window*			_window;
		SDL_GLContext		_glContext;
		int					_width;
		int					_height;
	public:
		Window(int width, int height, const char* title);
		~Window();
		inline int getWidth() const { return _width; }
		inline int getHeight() const { return _height; }
		void update();
	};
} }