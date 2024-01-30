#pragma once
#ifndef GAME_H
#define GAME_H

#include "includes.h"
int rand_();
class game
{
public:
	game(unsigned int x, unsigned int y, unsigned int seed);
	~game();
	void update();
	char*** active_table = nullptr;
private:
	unsigned int size_x;
	unsigned int size_y;
	char** rows1;
	char** rows2;
	char*** second_table = nullptr;
};


#endif // !GAME_H
