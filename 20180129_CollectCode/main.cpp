#pragma once
#include <iostream>
#include <Windows.h>
#include "myUtilityLibrary.h"

using namespace std;

// #define 지시문 = 전처리문
//#define FULLSCREEN_MODE
#define BULLETMAX 3

int main()
{
#ifdef FULLSCREEN_MODE
	cout << "풀 스크린 모드 입니다." << endl;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
#else
	cout << "창 모드 입니다." << endl;
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.right / 2, r.bottom / 2, 800, 300, TRUE);
#endif // FULLSCREEN_MODE
	srand(time(NULL));

	

	int bullet[BULLETMAX];

	for (int i = 0; i < BULLETMAX; ++i)
	{
		bullet[i] = i;
		cout << bullet[i] << endl;
	}
	cout << GetRandomInt(0, 10) << endl;
	cout << GetRandomInt(0, 10) << endl;
	cout << GetRandomInt(0, 10) << endl;

	/*
	int mapHorizontalCount = 0;
	int mapVerticalCount = 0;
	char *mapLines[] = {
	"┌ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┐",
	"│   │   │   │   │   │",
	"├ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼",
	"│   │   │   │   │   │",
	"├ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼",
	"│   │   │   │   │   │",
	"├ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼",
	"│   │   │   │   │   │",
	"├ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼",
	"│   │   │   │   │   │",
	"└ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┘"
	};

	// 문자열(char*) 배열의 첫 번째 배열을 가리키는(*) pMapLine 포인터 변수 -> 문자열 배열의 첫 번째 행의 주소 가짐.
	char** pMapLine = &mapLines[0];
	char* mapPointer = *pMapLine;

	// * sizeof() 함수는 해당 변수에 할당된 메모리 크기를 반환함. -> 포인터 변수는 4바이트
	// * sizeof(mapLines)를 하면 문자열 배열에 할당된 문자열 포인터 변수들의 메모리 공간, 즉 행 * 4바이트(32bit 기준) 값이 나온다.
	// * sizeof(pMapLine)은 문자열 배열의 첫 번째 행을 가리키는 포인터 변수이므로 4바이트이다.
	// * 즉 결과는 (11 * 4) / 4 = 11(행)
	// * strlen()은 문자열의 총 길이(=문자들의 개수)를 반환함. 특수문자는 2바이트

	mapHorizontalCount = sizeof(mapLines) / sizeof(pMapLine);
	mapVerticalCount = strlen(*pMapLine);

	char* aa = "abcde";

	for (int i = 0; i < 5; ++i)
	{
	char c = (char)*aa;
	aa++;
	cout << c << endl;
	}

	*/

	return 0;
}