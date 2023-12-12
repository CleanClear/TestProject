#include <iostream>
#include <time.h>

using namespace std;

void OutputCard(int);
bool CheckCardNumber(int, int, int);

int main()
{
	srand(time(NULL));
	int cardNums[52];
	
	int myMoney = 1000000;
	int batting = 0;
	int nowIndex = 0;

	for (int i = 0; i < 52; ++i)
	{
		cardNums[i] = i;
	}

	int dest, sour, temp;

	for (int i = 0; i < 200; ++i)
	{
		dest = (int)((double)rand() / RAND_MAX * 52);
		sour = (int)((double)rand() / RAND_MAX * 52);

		temp = cardNums[dest];
		cardNums[dest] = cardNums[sour];
		cardNums[sour] = temp;
	}

	while (nowIndex < 51 && myMoney >= 1000)
	{
		// intro
		system("cls");
		cout << "-------------------------ī �� �� �� �� ��-------------------------" << endl;
		cout << "���� �� : ù ��°�� �� ��° ī�带 �����ְ� �� ��° ī���� ���ڰ�\n\t  �� ī�� ���� ������ ������ ���߸� ���ñݾ� X 2�� ȹ��." << "\n\n";
		cout << "���� ������ : " << myMoney << endl;
		cout << "���� ī�� ���� : " << 52 - nowIndex << endl;

		// ī�� ��ġ
		cout << "ù ��° ī�� : ";
		OutputCard(cardNums[nowIndex]);

		cout << "�� ��° ī�� : ";
		OutputCard(cardNums[nowIndex + 1]);

		cout << "������ �ݾ��� �Է��Ͻÿ�(�ּ� 1000��) : ";
		cin >> batting;

		if (batting < 1000 || batting > myMoney)
		{
			// ������ ������ ���ڿ��� �Է��� ��� ������ �߻��ϱ� ������ ���۸� ������ ��.
			// cin.clear() �Լ��� ���� ���� �÷��׸� �ʱ�ȭ���Ѽ� cin�� ���������� �۵��ϵ��� ��.
			// cin.ignore(100, '\n') �̷� ������ ����ϸ� 100���� ���ڰ� �Էµǰų� ���Ͱ�
			// �ԷµǱ� ������ �Է� �������� �ִ� ������ ���� �����ؼ� ����.
			// numeric_limits<streamsize>::max() ������ ��Ÿ�� �� �ִ� �ִ� �������� �������� �Լ��ε��ϴ�.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���� �ݾ��� �ּ� 1000���̻� ������ �̳����� �������ּ���.";
			_sleep(2000);
			continue;
		}

		myMoney -= batting;

		cout << "�� ��° ī�� : ";
		OutputCard(cardNums[nowIndex + 2]);

		if (CheckCardNumber(cardNums[nowIndex], cardNums[nowIndex + 1], cardNums[nowIndex + 2])){
			cout << "���߼̽��ϴ�~ ������ �ݾ��� �� �踦 ȹ���ϼ̽��ϴ�. �����մϴ�.";
			myMoney += batting * 2;
		}

		nowIndex += 3;
		_sleep(2000);
	}

	if (myMoney < 1000)
		cout << "�� �� ����? ���� ����!!!" << endl;

	return 0;
}

void OutputCard(int card)
{
	int shapeStyle = card / 13;
	int cardNumber = card % 13;
	char* cardShape[4] = { "��", "��", "��", "��" };
	
	switch (cardNumber)
	{
	case 0:
		cout << cardShape[shapeStyle] << "A" << endl;
		break;
	case 10:
		cout << cardShape[shapeStyle] << "J" << endl;
		break;
	case 11:
		cout << cardShape[shapeStyle] << "Q" << endl;
		break;
	case 12:
		cout << cardShape[shapeStyle] << "K" << endl;
		break;
	default:
		cout << cardShape[shapeStyle] << cardNumber + 1 << endl;
		break;
	}
}

bool CheckCardNumber(int firstCard, int secondCard, int thirdCard)
{
	int firstCardNumber = firstCard % 13;
	int secondCardNumber = secondCard % 13;
	int thirdCardNumber = thirdCard % 13;
	bool success = false;

	if (abs(firstCardNumber - secondCardNumber) < 2)
		return false;

	if (firstCardNumber > secondCardNumber)
	{
		if (firstCardNumber > thirdCardNumber &&
			secondCardNumber < thirdCardNumber)
			success = true;
	}
	else
	{
		if (firstCardNumber < thirdCardNumber &&
			secondCardNumber > thirdCardNumber)
			success = true;
	}
	
	return success;
}