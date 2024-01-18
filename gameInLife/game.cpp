#include "game.h"

static unsigned long long int next = 1;

int rand_()
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

void srand_(unsigned int seed) 
{
	next = seed;
}

game::game(unsigned int x, unsigned int y, unsigned int seed)
{
	srand_(seed);
	size_x = x;
	size_y = y;
	if (x < 5)
		throw std::invalid_argument("X must be greater or equal 5");
	if (y < 5)
		throw std::invalid_argument("Y must be greater or equal 5");
	rows1 = new bool* [y];
	rows2 = new bool* [y];
	for (int i = 0; i < y; ++i)
	{
		rows1[i] = new bool[x];
		rows2[i] = new bool[x];
		for (int j = 0; j < x; ++j)
		{
			rows1[i][j] = rand_() % 2;
			rows2[i][j] = 0;
		}
	}
	active_table = &rows1;
	second_table = &rows2;
}

game::~game()
{
	for (int i = 0; i < size_y; ++i)
		delete[] rows1[i];
	delete[] rows1;

	for (int i = 0; i < size_y; ++i)
		delete[] rows2[i];
	delete[] rows2;
}

void game::update()
{
	for (int i = 0; i < size_y; ++i)
	{
		for (int j = 0; j < size_x; ++j)
		{
			
			int k = 0;
			k += (int)((*active_table)[(i - 1 + size_y) % size_y][(j - 1 + size_x) % size_x]);
			k += (int)((*active_table)[(i - 1 + size_y) % size_y][j]);
			k += (int)((*active_table)[(i - 1 + size_y) % size_y][(j + 1) % size_x]);
			k += (int)((*active_table)[i][(j - 1 + size_x) % size_x]);
			k += (int)((*active_table)[i][(j + 1) % size_x]);
			k += (int)((*active_table)[(i + 1) % size_y][(j - 1 + size_x) % size_x]);
			k += (int)((*active_table)[(i + 1) % size_y][j]);
			k += (int)((*active_table)[(i + 1) % size_y][(j + 1) % size_x]);
			// vvv - rules
			if (k == 3)
				(*second_table)[i][j] = 1;
			else
			{
				if (k == 2 && (*active_table)[i][j])
					(*second_table)[i][j] = 1;
				else
					(*second_table)[i][j] = 0;
			}
			// ^^^ - rules
		}
	}
	bool*** t_table = active_table;
	active_table = second_table;
	second_table = t_table;
}