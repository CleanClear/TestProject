#pragma once
#include <iostream>
#include <Windows.h>
#include "myUtilityLibrary.h"

using namespace std;

// #define ���ù� = ��ó����
//#define FULLSCREEN_MODE
#define BULLETMAX 3

int main()
{
#ifdef FULLSCREEN_MODE
	cout << "Ǯ ��ũ�� ��� �Դϴ�." << endl;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
#else
	cout << "â ��� �Դϴ�." << endl;
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
	"�� �� �� �� �� �� �� �� �� �� ��",
	"��   ��   ��   ��   ��   ��",
	"�� �� �� �� �� �� �� �� �� �� ��",
	"��   ��   ��   ��   ��   ��",
	"�� �� �� �� �� �� �� �� �� �� ��",
	"��   ��   ��   ��   ��   ��",
	"�� �� �� �� �� �� �� �� �� �� ��",
	"��   ��   ��   ��   ��   ��",
	"�� �� �� �� �� �� �� �� �� �� ��",
	"��   ��   ��   ��   ��   ��",
	"�� �� �� �� �� �� �� �� �� �� ��"
	};

	// ���ڿ�(char*) �迭�� ù ��° �迭�� ����Ű��(*) pMapLine ������ ���� -> ���ڿ� �迭�� ù ��° ���� �ּ� ����.
	char** pMapLine = &mapLines[0];
	char* mapPointer = *pMapLine;

	// * sizeof() �Լ��� �ش� ������ �Ҵ�� �޸� ũ�⸦ ��ȯ��. -> ������ ������ 4����Ʈ
	// * sizeof(mapLines)�� �ϸ� ���ڿ� �迭�� �Ҵ�� ���ڿ� ������ �������� �޸� ����, �� �� * 4����Ʈ(32bit ����) ���� ���´�.
	// * sizeof(pMapLine)�� ���ڿ� �迭�� ù ��° ���� ����Ű�� ������ �����̹Ƿ� 4����Ʈ�̴�.
	// * �� ����� (11 * 4) / 4 = 11(��)
	// * strlen()�� ���ڿ��� �� ����(=���ڵ��� ����)�� ��ȯ��. Ư�����ڴ� 2����Ʈ

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