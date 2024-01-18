#pragma once
#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <string>
#ifdef __unix__
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#endif
#endif // !INCLUDES_H