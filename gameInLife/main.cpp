#include "graphicsEngine.h"
#include "game.h"
#include "includes.h"

int main()
{
	int size_y = 250;
	int size_x = 300;
	int seed;
	std::cin >> seed;
	game g_class(size_x, size_y, seed);
	graphicsEngine ge(size_x, size_y);

	while (1)
	{
		ge.update(*g_class.active_table);
		g_class.update();
		//Sleep(1);
	}
	return 0;
}