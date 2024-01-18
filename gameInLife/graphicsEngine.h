#pragma once
#ifndef GRAPHICS_ENGINEHH
#define GRAPHICS_ENGINE_H

#include "includes.h"

#define PIXEL_SIZE_X 4
#define PIXEL_SIZE_Y 4

class graphicsEngine
{
public:
	graphicsEngine(unsigned int x, unsigned int y);
	~graphicsEngine();

	void update(bool** dispRows);
private:
	unsigned int size_x;
	unsigned int size_y;
	int width;
	int height;
};


#endif // !GRAPHICS_ENGINE.H