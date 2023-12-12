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
	// memset �Լ��� ù ��° �Ķ���Ͱ� ����Ű�� ���� ��ġ(=�ּ�)�� ����
	// �� ��° �Ķ������ ������ �ʱ�ȭ�ϴ� �Լ�.
	// �̶� �߿��� ���� �� ��° �Ķ������ ���� ��ü �޸� ������ ��Ÿ���Ƿ�
	// �ش� ������ ��ü �޸� �Ҵ� ũ�⸦ �־�� ��.
	// �Ʒ��� ���� �迭�� ��� int(4byte) * �迭 ���� ��ŭ ����� ��.
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
		cout << "--------------------------------------- 0 �� �� �� ---------------------------------------" << endl;
		cout << "���� : �ʿ� ���� 0�� ĳ����, 0�� ������������!" << endl;
		cout << "���۹� : ȭ��ǥŰ �Ǵ� wasd, ����Ű�е��� 8462 �Ǵ� 8465�� ������" << endl;
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
		cout << "0�� �̵���Ű���� -->> ";

		if (InputKey())
		{
			cout << "������ �����մϴ�." << endl;
			break;
		}
	}
	
	return bContinueGame;
}

bool zeroNum::InputKey()
{
	bool endGame = false;
	// _getch() �Լ��� ���۰� ���� ������ �Է� ��� ����Ű�� ������ �ʾƵ� �Է��� �Ϸ�ȴ�.
	// ȭ��ǥŰ�� ���� Ư��Ű�� ���Ű�� 2byte�̱� ������ �ƽ�Ű�ڵ��� 1byte�� �Ѿ��.
	// �׷��� ������ 2byte Ű�� �Է¹��� ���� _getch() �Լ��� �� �� ȣ���Ѵ�.
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
			// ����Ű�е�� wasd Ű �Է�
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