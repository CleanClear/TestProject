#include "zeroNum.h"



zeroNum::zeroNum()
{
	InitializeGame();
	StartGame();
}


zeroNum::~zeroNum()
{
	if(m_pNumBoard)
		delete[] m_pNumBoard;
}

void zeroNum::InitializeGame()
{
	srand(time(NULL));
	m_zeroLocation = 0;
	m_pNumBoard = new int[BOARD_SIZE];
	// memset 함수는 첫 번째 파라미터가 가리키는 변수 위치(=주소)의 값을
	// 두 번째 파라미터의 값으로 초기화하는 함수.
	// 이때 중요한 것은 세 번째 파라미터의 값은 전체 메모리 범위를 나타내므로
	// 해당 변수의 전체 메모리 할당 크기를 넣어야 함.
	// 아래와 같이 배열일 경우 int(4byte) * 배열 길이 만큼 해줘야 함.
	memset(m_pNumBoard, 0, BOARD_SIZE * sizeof(m_pNumBoard));
	
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		m_pNumBoard[i] = i + 1;
	}

	int dest, sour, temp;
	for (int i = 0; i < 1000; ++i)
	{
		dest = RANDOM_MACRO(BOARD_SIZE);
		sour = RANDOM_MACRO(BOARD_SIZE);

		temp = m_pNumBoard[dest];
		m_pNumBoard[dest] = m_pNumBoard[sour];
		m_pNumBoard[sour] = temp;
	}
}

bool zeroNum::StartGame()
{
	bool bContinueGame = false;

	while (true)
	{
		system("cls");
		cout << "--------------------------------------- 0 의 모 험 ---------------------------------------" << endl;
		cout << "설명 : 맵에 숫자 0이 캐릭터, 0을 움직여보세요!" << endl;
		cout << "조작법 : 화살표키 또는 wasd, 숫자키패드의 8462 또는 8465로 움직임" << endl;
		cout << endl;

		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			if (i > 0 && i % MAP_COLSIZE == 0)
				cout << "\n\n";

			if (i == m_zeroLocation)
				cout << 0 << "\t";
			else
				cout << m_pNumBoard[i] << "\t";
		}
		cout << "\n\n";
		cout << "0을 이동시키세요 -->> ";

		if (InputKey())
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	
	return bContinueGame;
}

bool zeroNum::InputKey()
{
	bool endGame = false;
	// _getch() 함수는 버퍼가 없기 때문에 입력 즉시 엔터키를 누르지 않아도 입력이 완료된다.
	// 화살표키와 같이 특수키나 평션키는 2byte이기 때문에 아스키코드의 1byte를 넘어선다.
	// 그렇기 때문에 2byte 키를 입력받을 때는 _getch() 함수를 두 번 호출한다.
	int inputValue = _getch();
	int secondValue = 0;

	if (inputValue == EXPEND_KEY)
	{
		secondValue = _getch();
		switch (secondValue)
		{
		case UP_ARROW:
			m_zeroLocation -= (m_zeroLocation <= MAP_COLSIZE) ? 0 : MAP_COLSIZE;
			break;
		case DOWN_ARROW:
			m_zeroLocation += (m_zeroLocation >= BOARD_SIZE - MAP_COLSIZE) ? 0 : MAP_COLSIZE;
			break;
		case LEFT_ARROW:
			m_zeroLocation -= (m_zeroLocation % MAP_COLSIZE == 0) ? 0 : 1;
			break;
		case RIGHT_ARROW:
			m_zeroLocation += (m_zeroLocation % MAP_COLSIZE == 4) ? 0 : 1;
			break;
		}
	}
	else
	{
		if (inputValue == ESC_KEY)
			endGame = true;
		else
		{
			// 숫자키패드와 wasd 키 입력
			if(inputValue == VK_w || inputValue == VK_8)
				m_zeroLocation -= (m_zeroLocation <= MAP_COLSIZE) ? 0 : MAP_COLSIZE;
			else if(inputValue == VK_s || inputValue == VK_5 || inputValue == VK_2)
				m_zeroLocation += (m_zeroLocation >= BOARD_SIZE - MAP_COLSIZE) ? 0 : MAP_COLSIZE;
			else if(inputValue == VK_a || inputValue == VK_4)
				m_zeroLocation -= (m_zeroLocation % MAP_COLSIZE == 0) ? 0 : 1;
			else if(inputValue == VK_d || inputValue == VK_6)
				m_zeroLocation += (m_zeroLocation % MAP_COLSIZE == 4) ? 0 : 1;
		}
	}

	return endGame;
}