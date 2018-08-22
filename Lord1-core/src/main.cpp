#include <iostream>
#include "application.h"

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "[ERROR] SDL failed to initialize!" << std::endl;
	}
	else
	{
		lord::Application app("Lord engine");
		app.run();
	}
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get();
	return 0;
}