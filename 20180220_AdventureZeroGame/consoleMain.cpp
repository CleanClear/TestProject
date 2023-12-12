#pragma once
#include "mainGame.h"

int main()
{

#ifdef FULLSCREEN_MODE
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
#else
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.right / 2, r.bottom / 2, 800, 300, TRUE);
#endif // FULLSCREEN_MODE

	mainGame mg;
	return 0;
}