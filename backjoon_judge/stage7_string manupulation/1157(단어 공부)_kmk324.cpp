//�ܾ����
//��������
//1. 26+26(��ҹ��� ��) ũ���� �迭 ����. �� �ε����� �ش� ���� 0���� �ʱ�ȭ. //0~25�빮��. 26~51�ҹ���.AlphaCount
//2. �빮���϶� ���̽��� �ҹ����� �� ���̽��� ����.
//3. for 0���� 51���� ���� ���� ���� ī��Ʈ�� �迭 ã�� �� �ε����� ���ĺ����.
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
		if (Question[i] > 90) //�ҹ���.
		{
			AlphaCount[Question[i] - 97+26] += 1;
		}
		else //�빮��
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