#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int bingoNumbers[25] = { 0, };
	int inputNum = 0;
	int dest, sour, temp;
	int bingoCount = 0;

	for (int i = 0; i < 25; ++i)
	{
		bingoNumbers[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		dest = (int)((double)rand() / RAND_MAX * 25);
		sour = (int)((double)rand() / RAND_MAX * 25);

		temp = bingoNumbers[dest];
		bingoNumbers[dest] = bingoNumbers[sour];
		bingoNumbers[sour] = temp;
	}

	while (true)
	{
		system("cls");
		cout << "------------------------BINGO GAME----------------------------" << endl;
		cout << bingoCount << " 개 빙고" << endl;

		for (int i = 0; i < 25; ++i)
		{
			// #을 표시했는지 확인 -> # = (char)35
			if (bingoNumbers[i] == 35)
				cout << (char)bingoNumbers[i] << "\t";
			else
				cout << bingoNumbers[i] << "\t";

			if ((i + 1) % 5 == 0) cout << "\n\n\n";

		}

		bingoCount = 0;

		cout << "숫자 입력해봐염~ ☞ ";
		cin >> inputNum;

		for (int i = 0; i < 25; i++)
		{
			if (bingoNumbers[i] == inputNum)
			{
				bingoNumbers[i] = 35;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (bingoNumbers[i * 5] == 35 &&
				bingoNumbers[i * 5 + 1] == 35 &&
				bingoNumbers[i * 5 + 2] == 35 &&
				bingoNumbers[i * 5 + 3] == 35 &&
				bingoNumbers[i * 5 + 4] == 35)
			{
				bingoCount++;
			}

			if (bingoNumbers[i] == 35 &&
				bingoNumbers[i + 5] == 35 &&
				bingoNumbers[i + 5 * 2] == 35 &&
				bingoNumbers[i + 5 * 3] == 35 &&
				bingoNumbers[i + 5 * 4] == 35)
			{
				bingoCount++;
			}
		}

		if (bingoNumbers[0] == 35 &&
			bingoNumbers[6] == 35 &&
			bingoNumbers[12] == 35 &&
			bingoNumbers[18] == 35 &&
			bingoNumbers[24] == 35)
		{
			bingoCount++;
		}

		if (bingoNumbers[4] == 35 &&
			bingoNumbers[8] == 35 &&
			bingoNumbers[12] == 35 &&
			bingoNumbers[16] == 35 &&
			bingoNumbers[20] == 35)
		{
			bingoCount++;
		}
	}



	return 0;
}