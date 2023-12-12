#include <iostream>

using namespace std;

int main()
{
	// str���� �Լ���
	// 1. strlen
	// ���ڿ��� ���̸� ���������� ��ȯ���ִ� �Լ�
	
	char* pStr = "abdefg";
	int length = strlen(pStr);

	cout << "���ڿ��� ���̴� ? " << length << endl;

	// 2. strcmp
	// �� ���ڿ��� ���ؼ� ������ ũ�� 1, �������� ũ�� -1, ������ 0�� ��ȯ
	
	char* pStr2 = "asdf";
	char* pStr3 = "ffff";
	int cmpValue = strcmp(pStr2, pStr3);

	cout << "cmp ����? : " << cmpValue << endl;

	// 3. strcat
	// strcat(���ڿ�1, ���ڿ�2) ����ϸ�
	// ���ڿ�1 �ڿ� ���ڿ�2�� �̾����.
	// ���ڿ�1�� �̸� ���������� �δ°� ����.

	char str4[30] = "������ �ձ�";
	char* pStr5 = ".avi";

	cout << str4 << endl;
	cout << strcat(str4, pStr5) << endl;

	// 4. strcpy
	// strcpy(���ڿ�1, ���ڿ�2)
	// ���ڿ�2�� ���ڿ��� ���ڿ�1�� �����Ѵ�.
	// 3���� ���������� ���ڿ�1�� ������ ���ڿ�2 ������ŭ �־�� ��.

	char str6[10];
	char* pStr7 = "wow";
	strcpy(str6, pStr7);

	cout << str6 << endl;

	// 5.strtok
	// ���ڿ��� Ư�� �����ڷ� �ڸ��� ���� �� ���.
	// �Է��Լ��� �����ϰ� ���
	// scanf : ����, �����̽�, �� ������ �Է� ����
	// gets : ���ͷθ� �Է� ����
	// cin : 

	char* separator = " ";
	char* token;
	char inputStr[32];

	cout << "���ڿ��� �Է��Ͻÿ� : ";
	gets_s(inputStr, 32);

	token = strtok(inputStr, separator);
	cout << token << endl;

	// strtok ù ��° ���ڸ� NULL�� ���� ���
	// ó���� �־��� ���ڿ��� �ڸ��� �� ���� ���� ������ ��ġ���� �ڸ��� ��.
	// ��, ó�� �־��� ù ��° ������ �����͸� ������ �����Ƿ� NULL�� ������
	// ��� �̾ �ڸ��� ��.

	while (NULL != (token = strtok(NULL, separator))) 
	{
		cout << token << endl;
	}
	
	return 0;
}