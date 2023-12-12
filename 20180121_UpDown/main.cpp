#include <iostream>				// cout, cin�� ���� ����� �Լ� ����.
#include <time.h>				// �ð� ���� ���� �Լ� ����

using namespace std;			// �Լ��� ����ϱ� ���� ���ӽ����̽� ex) std::cout, std::srand

int main()
{
	srand(time(NULL));
	// srand(����)�� �ش� Seed ���� ���ؼ� Ư�� ���� �� ����.
	// ��, �Է� ���� ������ �Ź� ���� ������ ���� ���� ����.
	// �׷��� ������ ���� �ٸ� ������ �߻���Ű�� ���� time(NULL)�� �־� �ð��� ���ؼ� ���� �߻�.
	// rand() �Լ��� 0 ~ RAND_MAX ������ ���� �� ����.
	// cout << RAND_MAX << endl;

	int rndNum = rand() % 1000;				// 0 ~ 999 ���� ���� �߻�.
	int inputNum = 0;
	int roundNum = 9;

	while (true)
	{
		cout << "��ǻ�Ͱ� ���� ���ڰ� ����?" << endl;
		cout << "���� �Է��Ͻÿ�(0 ~ 999) : ";
		cin >> inputNum;

		if (inputNum < 0 || inputNum > 999)
		{
			cout << "�ٽ� �Է��ϼ���." << endl;
			continue;
		}

		if (inputNum > rndNum)
			cout << "�Է��� ������ �۽��ϴ�." << endl;
		else if (inputNum < rndNum)
			cout << "�Է��� ������ Ů�ϴ�." << endl;

		cout << "���� ���� �� : " << roundNum << endl;

		if (inputNum == rndNum)
		{
			cout << "����~~~~!!!! ��ī��ī" << endl;
			break;
		}

		if (roundNum <= 0)
		{
			cout << "���� �� ���߳�... ������ : " << rndNum << endl;
			break;
		}

		roundNum--;
	}

	return 0;
}