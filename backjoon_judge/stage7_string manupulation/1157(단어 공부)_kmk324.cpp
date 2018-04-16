//단어공부
//문제구상
//1. 26+26(대소문자 수) 크기의 배열 선언. 각 인덱스의 해당 값을 0으로 초기화. //0~25대문자. 26~51소문자.AlphaCount
//2. 대문자일때 케이스와 소문자일 때 케이스를 나눔.
//3. for 0부터 51까지 돌며 가장 높은 카운트의 배열 찾고 그 인덱스의 알파벳출력.
#include<iostream>
#include <string>
using namespace std;
int main()
{
	int AlphaCount[52] = { 0 };
	char maxCountingChar;
	string Question;
	cin >> Question;
	for (int i = 0; i < Question.length(); i++)
	{
		if (Question[i] > 90) //소문자.
		{
			AlphaCount[Question[i] - 97+26] += 1;
		}
		else //대문자
		{
			AlphaCount[Question[i] - 65] +=1;
		}
	}

	int max=0;
	int sameCount = 0;
	int AnsIndex;
	for (int i = 0; i < 52; i++)
	{
		if (max < AlphaCount[i])
		{
			max = AlphaCount[i];
			AnsIndex = i;
		}
	}

	for (int i = 0; i < 52; i++)
	{
		if (max == AlphaCount[i])
		{
			sameCount++;
		}
		if (sameCount == 2)
		{
			maxCountingChar='?';
			break;
		}
	}

	if (maxCountingChar != '?')
	{
		if (AnsIndex > 25)
		{
			maxCountingChar = AnsIndex + 71;
		}
		else
		{
			maxCountingChar = AnsIndex + 65;
		}
	}
	cout << maxCountingChar << endl;
	return 0;
}