#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#pragma region Key Input Define

#define EXPEND_KEY 0xE0		// =224
#define ESC_KEY 27	
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80

#define VK_w 119
#define VK_s 115
#define VK_a 97
#define VK_d 100

#define VK_8 56
#define VK_5 53
#define VK_2 50
#define VK_4 52
#define VK_6 54

#pragma endregion

void FullScreenMode();
void WindowDisplayMode(int x, int y, int width, int height);
int GetRandomInt(int rangeMin, int rangeMax);