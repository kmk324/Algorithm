//그룹단어 체킹.
#include<iostream>
#include <string>
using namespace std;
// 구상
// 1.알파벳 소문자 26개 크기의 배열을 선언후. 각 인덱스에 카운트0 할당. 
// 2.해당 알파밧의 인덱스 공간에 할당된 값이 0인지 확인. 
// 3. 아니라면 그 전라운드에서 카운트를 ++했는지 확인.
int main()
{
	int ArphabetCount[26] = { 0 };
	int Ans = 0;
	int TestNum;
	bool IsGroupWord = true;
	string QuestionWord;
	cin >> TestNum;
	while (TestNum--)
	{
		cin >> QuestionWord;
		for (int i = 0; i < QuestionWord.length(); i++)
		{
			if (ArphabetCount[QuestionWord[i] - 97] == 0)
			{
				ArphabetCount[QuestionWord[i] - 97] += 1;
			}
			else
			{
				if (QuestionWord[i] == QuestionWord[i - 1])
				{

				}
				else
				{
					IsGroupWord = false; 
					break; //조건을 위반하므로 이번 케이스는 더 탐색할 필요가 없다.
				}
			}
		}
		if (IsGroupWord == true) //위반하는 케이스가 없었는가.
		{
			Ans++; 
		}
		//while문 다음 케이스를 위한 초기화.
		for (int i = 0; i < 26; i++)
		{
			ArphabetCount[i] = 0;
		}
		IsGroupWord = true;
	}
	cout << Ans;
}