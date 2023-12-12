#include "myUtilityLibrary.h"

void FullScreenMode()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void WindowDisplayMode(int x, int y, int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, x, y, width, height, TRUE);
}

int GetRandomInt(int rangeMin, int rangeMax)
{
	return rangeMin + (int)((double)rand() / (RAND_MAX) * (rangeMax));
}