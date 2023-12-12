#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int bbNumber[3] = {0, };				// �� 3���� ��ȣ
	int strike = 0;							// ��ġ�� ���� ������ ����� ��
	int ball = 0;							// ���� ������ ����� ��
	int inputNum = 0;						// ����ڰ� �Է��� ��
	int inputNumSplit[3] = { 0, };			// �Է��� ���� �ڸ����� �и�.
	int roundNum = 10;						// ���� ��

	// ���� 3�� �����ϰ� �ʱ�ȭ(0 ~ 9)
	bbNumber[0] = (int)((double)rand() / RAND_MAX * (10 - 2)) + 1;
	bbNumber[1] = (int)((double)rand() / RAND_MAX * (10 - 1));

	while (true)
	{
		if (bbNumber[0] == bbNumber[1]) {
			bbNumber[1] = (int)((double)rand() / RAND_MAX * (10 - 1));
			continue;
		}

		bbNumber[2] = (int)((double)rand() / RAND_MAX * (10 - 1));
		if (bbNumber[0] == bbNumber[2] || bbNumber[1] == bbNumber[2])
			continue;
		break;
	}

	cout << "----------------------------------------------------------" << endl;
	cout << " ���� �߱� ����! 3�ڸ� ���ڸ� ��Ȯ�ϰ� ���ߴ� ����!!!" << endl;
	cout << " Strike : �Է��� ������ ��ġ�� ���� ������ ��" << endl;
	cout << " Ball : �Է��� ������ ��ġ�� �ٸ����� ���� ���� ��" << endl;
	cout << " �� ���� ���� 10, ���� ��ŸƮ!" << endl;
	cout << "----------------------------------------------------------" << endl;

	// ���� ����
	while (roundNum > 0)
	{
		cout << "���ڸ� �Է��ϼ���(3�ڸ� ����, �� ù ��° �ڸ��� 0�� �� �� ����.) : ";
		cin >> inputNum;

		// �Է��� �� �˻�.
		if (inputNum < 0 || inputNum > 999 || inputNum / 100 <= 0)
		{
			cout << "ù ��° �ڸ� 0�� ������ 0 ~ 9 ������ ���ڷ� 3�ڸ��� �Է��ϼ���." << endl;
			continue;
		}
		
		roundNum--;
		cout << "�Է��� �� : " << inputNum << endl;

		// �Է°� �ڸ����� �°� ����.
		for (int i = 2; i >= 0; --i)
		{
			inputNumSplit[i] = inputNum % 10;
			inputNum = inputNum / 10;
		}

		for (int i = 0; i < 3; ++i)
		{
			if (inputNumSplit[i] == bbNumber[i])
				strike++;
		}

		if (strike < 3)
		{
			if (inputNumSplit[0] == bbNumber[1] || inputNumSplit[0] == bbNumber[2])
				ball++;

			if (inputNumSplit[1] == bbNumber[0] || inputNumSplit[1] == bbNumber[2])
				ball++;

			if (inputNumSplit[2] == bbNumber[0] || inputNumSplit[2] == bbNumber[1])
				ball++;
		}
		else
			break;

		cout << "Strike : " << strike << " Ball : " << ball << endl;
		cout << "���� ���� : " << roundNum << endl << endl;
		strike = ball = 0;
	}

	if (strike < 3)
		cout << "���� �̰͵� �� ���߳�! ������ : " << bbNumber[0] << bbNumber[1] << bbNumber[2] << " �̴�!!" << endl;
	else
		cout << "�� ��ī��ī~ ������ ���߼̾��~" << endl;
	
	return 0;
}