#include <iostream>

using namespace std;

int main()
{
	// str관련 함수들
	// 1. strlen
	// 문자열의 길이를 정수값으로 반환해주는 함수
	
	char* pStr = "abdefg";
	int length = strlen(pStr);

	cout << "문자열의 길이는 ? " << length << endl;

	// 2. strcmp
	// 두 문자열을 비교해서 왼쪽이 크면 1, 오른쪽이 크면 -1, 같으면 0을 반환
	
	char* pStr2 = "asdf";
	char* pStr3 = "ffff";
	int cmpValue = strcmp(pStr2, pStr3);

	cout << "cmp 값은? : " << cmpValue << endl;

	// 3. strcat
	// strcat(문자열1, 문자열2) 사용하면
	// 문자열1 뒤에 문자열2를 이어붙임.
	// 문자열1은 미리 여유공간을 두는게 좋다.

	char str4[30] = "동물의 왕국";
	char* pStr5 = ".avi";

	cout << str4 << endl;
	cout << strcat(str4, pStr5) << endl;

	// 4. strcpy
	// strcpy(문자열1, 문자열2)
	// 문자열2의 문자열을 문자열1로 복사한다.
	// 3번과 마찬가지로 문자열1의 공간이 문자열2 공간만큼 있어야 함.

	char str6[10];
	char* pStr7 = "wow";
	strcpy(str6, pStr7);

	cout << str6 << endl;

	// 5.strtok
	// 문자열을 특정 구분자로 자르고 싶을 때 사용.
	// 입력함수를 적절하게 사용
	// scanf : 엔터, 스페이스, 탭 등으로 입력 구분
	// gets : 엔터로만 입력 구분
	// cin : 

	char* separator = " ";
	char* token;
	char inputStr[32];

	cout << "문자열을 입력하시오 : ";
	gets_s(inputStr, 32);

	token = strtok(inputStr, separator);
	cout << token << endl;

	// strtok 첫 번째 인자를 NULL로 넣을 경우
	// 처음에 넣었던 문자열을 자르고 난 뒤의 다음 포인터 위치부터 자르게 함.
	// 즉, 처음 넣었던 첫 번째 인자의 포인터를 가지고 있으므로 NULL을 넣으면
	// 계속 이어서 자르게 됨.

	while (NULL != (token = strtok(NULL, separator))) 
	{
		cout << token << endl;
	}
	
	return 0;
}