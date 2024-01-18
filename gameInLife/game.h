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
	bool*** active_table = nullptr;
private:
	unsigned int size_x;
	unsigned int size_y;
	bool** rows1;
	bool** rows2;
	bool*** second_table = nullptr;
};


#endif // !GAME_H