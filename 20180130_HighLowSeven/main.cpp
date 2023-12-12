#include <iostream>
#include <time.h>
#include <Windows.h>
#include <limits>

//#define FULLSCREEN_MODE
#define CARDMAX 52
#define RANDUM_MACRO(x) (int)((double)rand() / (RAND_MAX) * (x))
#undef max

using namespace std;

void SetSizeConsoleWindow();
bool ShuffleCards(int*, int, int);
void OutputCard(int);
bool GotoXY(int, int);
COORD GetXY();

int main()
{
	srand(time(NULL));
	SetSizeConsoleWindow();

#pragma region Initialize Game
	
	int cardNum[CARDMAX];
	int nowCardIndex = 0;
	int batting = 0;
	int myMoney = 1000000;
	COORD nowCursorPoint;

	for (int i = 0; i < CARDMAX; ++i)
	{
		cardNum[i] = i;
	}

	ShuffleCards(cardNum, CARDMAX, 1000);

#pragma endregion

#pragma region Start Game!

	while (nowCardIndex < CARDMAX - 4)
	{
		system("cls");
		cout << "------------------------------ HIGH LOW SEVEN GAME ------------------------------" << endl;
		cout << "하이로우세븐 게임 룰 : 처음 게임을 시작하면 4장의 카드를 오픈합니다. 다음에 나올" << endl;
		cout << "\t\t       카드의 숫자가 7보다 크면 High, 7보다 작으면 Low, 7이면" << endl;
		cout << "\t\t       Seven이고 숫자를 예상하여 배팅하는 게임입니다.\n" << endl;

		for (int i = 0; i < 4; ++i)
		{
			OutputCard(cardNum[nowCardIndex + i]);
			if (i < 3) 
				cout << "  ";
			else {
				cout << "  ";
				nowCursorPoint = GetXY();
				cout << endl << endl;
			}
		}
		
		cout << "현재 남은 소지금 : " << myMoney << endl;
		cout << "현재 남은 카드 숫자 : " << CARDMAX - nowCardIndex - 4 << endl;
		cout << "베팅할 금액을 입력하세요 (최소 금액 = 1000원) : ";
		cin >> batting;

		if (batting < 1000 || batting > myMoney)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "베팅 금액은 최소 1000원이상 소지금 이내에서 지출해주세요.";
			Sleep(2000);
			continue;
		}

		int lastCardNum = cardNum[nowCardIndex + 4] % 13 + 1;

		break;
	}

#pragma endregion

	return 0;
}

void SetSizeConsoleWindow()
{
#ifdef FULLSCREEN_MODE
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
#else
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.right / 2, r.bottom / 2, 800, 500, TRUE);
#endif // FULLSCREEN_MODE
}

bool ShuffleCards(int* cards, int maxLength, int count)
{
	int dest, sour, temp;

	if (!cards || count < 0 || maxLength < 0)
		return false;

	for (int i = 0; i < count; ++i)
	{
		dest = RANDUM_MACRO(maxLength);
		sour = RANDUM_MACRO(maxLength);

		temp = cards[dest];
		cards[dest] = cards[sour];
		cards[sour] = temp;
	}

	return true;
}

void OutputCard(int card)
{
	int shapeStyle = card / 13;
	int cardNumber = card % 13;
	char* cardShape[4] = { "◆", "♠", "♣", "♥" };

	switch (cardNumber)
	{
	case 0:
		cout << cardShape[shapeStyle] << "A";
		break;
	case 10:
		cout << cardShape[shapeStyle] << "J";
		break;
	case 11:
		cout << cardShape[shapeStyle] << "Q";
		break;
	case 12:
		cout << cardShape[shapeStyle] << "K";
		break;
	default:
		cout << cardShape[shapeStyle] << cardNumber + 1;
		break;
	}
}

bool GotoXY(int x, int y)
{
	COORD pos;   //short 타입의 X, Y 속성이 들어 있는 구조체이다.
	pos.X = x;
	pos.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetXY()
{
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf);
	pos.X = buf.dwCursorPosition.X;
	pos.Y = buf.dwCursorPosition.Y;
	return pos;
}