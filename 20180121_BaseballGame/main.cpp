#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int bbNumber[3] = {0, };				// 공 3개의 번호
	int strike = 0;							// 위치와 값이 동일한 경우의 값
	int ball = 0;							// 값만 동일한 경우의 값
	int inputNum = 0;						// 사용자가 입력한 값
	int inputNumSplit[3] = { 0, };			// 입력한 값을 자릿수로 분리.
	int roundNum = 10;						// 라운드 수

	// 숫자 3개 랜덤하게 초기화(0 ~ 9)
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
	cout << " 숫자 야구 게임! 3자리 숫자를 정확하게 맞추는 게임!!!" << endl;
	cout << " Strike : 입력한 숫자의 위치와 값이 동일할 때" << endl;
	cout << " Ball : 입력한 숫자의 위치는 다르지만 값이 있을 때" << endl;
	cout << " 총 라운드 수는 10, 게임 스타트!" << endl;
	cout << "----------------------------------------------------------" << endl;

	// 게임 시작
	while (roundNum > 0)
	{
		cout << "숫자를 입력하세요(3자리 숫자, 단 첫 번째 자리는 0이 올 수 없음.) : ";
		cin >> inputNum;

		// 입력한 값 검사.
		if (inputNum < 0 || inputNum > 999 || inputNum / 100 <= 0)
		{
			cout << "첫 번째 자리 0을 제외한 0 ~ 9 사이의 숫자로 3자리를 입력하세요." << endl;
			continue;
		}
		
		roundNum--;
		cout << "입력한 값 : " << inputNum << endl;

		// 입력값 자릿수에 맞게 분할.
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
		cout << "남은 라운드 : " << roundNum << endl << endl;
		strike = ball = 0;
	}

	if (strike < 3)
		cout << "쯔쯔 이것도 못 맞추냐! 정답은 : " << bbNumber[0] << bbNumber[1] << bbNumber[2] << " 이다!!" << endl;
	else
		cout << "오 추카추카~ 정답을 맞추셨어요~" << endl;
	
	return 0;
}