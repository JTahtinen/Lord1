#pragma once
#include "graphics\window.h"

namespace Lord1 {

	using namespace graphics;

	class Application
	{
		Window		_window;
	public:
		Application(const char* title);
		~Application();
		void run();
	private:
		static void initEngine();
	};
}