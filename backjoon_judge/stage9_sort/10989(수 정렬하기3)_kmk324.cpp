#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// �� �����ϱ� 3
// ī���� ������ ����ؾ��Ѵ�. (�޸������� 8mb)

int main()
{
	int countingNum[10001] = { 0 };
	int N,intoDataNum;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d", &intoDataNum);
		countingNum[intoDataNum]++;
	}
	for (int i = 0; i <= 10000; i++)
	{
		for (int j = 0; j < countingNum[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}