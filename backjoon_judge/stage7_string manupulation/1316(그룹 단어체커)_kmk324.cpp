//�׷�ܾ� üŷ.
#include<iostream>
#include <string>
using namespace std;
// ����
// 1.���ĺ� �ҹ��� 26�� ũ���� �迭�� ������. �� �ε����� ī��Ʈ0 �Ҵ�. 
// 2.�ش� ���Ĺ��� �ε��� ������ �Ҵ�� ���� 0���� Ȯ��. 
// 3. �ƴ϶�� �� �����忡�� ī��Ʈ�� ++�ߴ��� Ȯ��.
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
					break; //������ �����ϹǷ� �̹� ���̽��� �� Ž���� �ʿ䰡 ����.
				}
			}
		}
		if (IsGroupWord == true) //�����ϴ� ���̽��� �����°�.
		{
			Ans++; 
		}
		//while�� ���� ���̽��� ���� �ʱ�ȭ.
		for (int i = 0; i < 26; i++)
		{
			ArphabetCount[i] = 0;
		}
		IsGroupWord = true;
	}
	cout << Ans;
}