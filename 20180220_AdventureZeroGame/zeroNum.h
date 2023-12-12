#pragma once
#define BOARD_SIZE 25
#define MAP_COLSIZE 5
#define RANDOM_MACRO(x) (int)((double)rand() / (RAND_MAX) * (x))

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

#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

class zeroNum
{
private:
	int *m_pNumBoard;
	int m_zeroLocation;

	void InitializeGame();
	bool StartGame();
	bool InputKey();

public:
	zeroNum();
	~zeroNum();
};

