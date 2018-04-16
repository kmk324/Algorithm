#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// 수 정렬하기 3
// 카운팅 정렬을 사용해야한다. (메모리제한이 8mb)

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