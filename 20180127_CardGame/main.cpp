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
		cout << "-------------------------카 드 베 팅 게 임-------------------------" << endl;
		cout << "게임 룰 : 첫 번째와 두 번째 카드를 보여주고 세 번째 카드의 숫자가\n\t  두 카드 숫자 사이의 값인지 맞추면 베팅금액 X 2배 획득." << "\n\n";
		cout << "현재 소지금 : " << myMoney << endl;
		cout << "남은 카드 개수 : " << 52 - nowIndex << endl;

		// 카드 배치
		cout << "첫 번째 카드 : ";
		OutputCard(cardNums[nowIndex]);

		cout << "두 번째 카드 : ";
		OutputCard(cardNums[nowIndex + 1]);

		cout << "베팅할 금액을 입력하시오(최소 1000원) : ";
		cin >> batting;

		if (batting < 1000 || batting > myMoney)
		{
			// 정수형 변수에 문자열을 입력할 경우 문제가 발생하기 때문에 버퍼를 비워줘야 함.
			// cin.clear() 함수는 내부 상태 플래그를 초기화시켜서 cin이 정상적으로 작동하도록 함.
			// cin.ignore(100, '\n') 이런 식으로 사용하면 100개의 문자가 입력되거나 엔터가
			// 입력되기 전까지 입력 시퀀스에 있는 내용을 전부 추출해서 버림.
			// numeric_limits<streamsize>::max() 정수로 나타낼 수 있는 최대 범위값을 가져오는 함수인듯하다.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "베팅 금액은 최소 1000원이상 소지금 이내에서 지출해주세요.";
			_sleep(2000);
			continue;
		}

		myMoney -= batting;

		cout << "세 번째 카드 : ";
		OutputCard(cardNums[nowIndex + 2]);

		if (CheckCardNumber(cardNums[nowIndex], cardNums[nowIndex + 1], cardNums[nowIndex + 2])){
			cout << "맞추셨습니다~ 베팅한 금액의 두 배를 획득하셨습니다. 축하합니다.";
			myMoney += batting * 2;
		}

		nowIndex += 3;
		_sleep(2000);
	}

	if (myMoney < 1000)
		cout << "돈 더 없어? 저리 꺼져!!!" << endl;

	return 0;
}

void OutputCard(int card)
{
	int shapeStyle = card / 13;
	int cardNumber = card % 13;
	char* cardShape[4] = { "◆", "♠", "♣", "♥" };
	
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