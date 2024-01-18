#include "graphicsEngine.h"

graphicsEngine::graphicsEngine(unsigned int x, unsigned int y)
{
	size_x = x;
	size_y = y;
	width = x * PIXEL_SIZE_X;
	height = y * PIXEL_SIZE_Y;
}

graphicsEngine::~graphicsEngine()
{
	return;
}

void graphicsEngine::update(bool** dispRows)
{
	cv::Mat screen = cv::Mat(height, width, CV_8UC3, cv::Scalar(0, 0, 0));
	static cv::Vec3b color(255, 0, 0);
	for (int y = 0; y < size_y; ++y)
	{
		for (int x = 0; x < size_x; ++x)
		{
			cv::Vec3b t1;
			if (dispRows[y][x])
			{
				/*t1[0] = color[0];
				t1[1] = color[1];
				t1[2] = color[2];
				*/
				for (int iy = 0; iy < PIXEL_SIZE_Y; ++iy)
				{
					for (int ix = 0; ix < PIXEL_SIZE_X; ++ix)
					{
						screen.at<cv::Vec3b>(y * PIXEL_SIZE_Y + iy, x * PIXEL_SIZE_X + ix) = color;
					}
				}
			}
		}
	}
	if (color[0] == 255 && color[2] == 0 && color[1] != 255)
		++color[1];
	else if (color[0] == 255 && color[2] > 0)
		--color[2];
	else if (color[1] == 255 && color[0] > 0)
		--color[0];
	else if (color[1] == 255 && color[0] == 0 && color[2] != 255)
		++color[2];
	else if (color[2] == 255 && color[1] > 0)
		--color[1];
	else if (color[2] == 255 && color[1] == 0 && color[0] != 255)
		++color[0];
	cv::imshow("Game in Life", screen);
	cv::waitKey(1);
	return;
}
