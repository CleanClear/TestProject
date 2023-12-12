#include <iostream>				// cout, cin과 같은 입출력 함수 내장.
#include <time.h>				// 시간 관련 내장 함수 제공

using namespace std;			// 함수를 사용하기 위한 네임스페이스 ex) std::cout, std::srand

int main()
{
	srand(time(NULL));
	// srand(정수)를 해당 Seed 값에 의해서 특정 난수 값 생성.
	// 단, 입력 값이 같으면 매번 실행 때마다 같은 난수 생성.
	// 그렇기 때문에 전혀 다른 난수를 발생시키기 위해 time(NULL)을 넣어 시간에 의해서 난수 발생.
	// rand() 함수는 0 ~ RAND_MAX 까지의 난수 값 생성.
	// cout << RAND_MAX << endl;

	int rndNum = rand() % 1000;				// 0 ~ 999 까지 난수 발생.
	int inputNum = 0;
	int roundNum = 9;

	while (true)
	{
		cout << "컴퓨터가 정한 숫자가 뭘까?" << endl;
		cout << "수를 입력하시오(0 ~ 999) : ";
		cin >> inputNum;

		if (inputNum < 0 || inputNum > 999)
		{
			cout << "다시 입력하세요." << endl;
			continue;
		}

		if (inputNum > rndNum)
			cout << "입력한 수보다 작습니다." << endl;
		else if (inputNum < rndNum)
			cout << "입력한 수보다 큽니다." << endl;

		cout << "남은 라운드 수 : " << roundNum << endl;

		if (inputNum == rndNum)
		{
			cout << "정답~~~~!!!! 추카추카" << endl;
			break;
		}

		if (roundNum <= 0)
		{
			cout << "정말 못 맞추네... 정답은 : " << rndNum << endl;
			break;
		}

		roundNum--;
	}

	return 0;
}