#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// 2108 통계학
//입력되는 정수의 절대값은 4000을 넘지 않는다. -> 음수도 -4000까지 가능.
int forMode[8001] = { 0 }; //최빈값.

//sort(배열이름+(시작인덱스), (배열이름)+(마지막인덱스+1))
//반올림 해줄 때 마이너스 수를 생각해야 하므로 floor 함수를 사용해야한다.
int main()
{
	int N, Num, Sum, ArithmeticMean, Median, Mode, Range;
	vector<int> forSort;
	vector<int>forModePrint;
	Sum = 0;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
	{
		scanf("%d", &Num);
		Sum += Num;
		forSort.push_back(Num);
		if (Num > 0)
		{
			forMode[Num+4000]++; //1~4000 -> 인덱스 4001~8000.
		}
		else {
			forMode[abs(Num)]++; //0~-4000 -> 인덱스 0~4000.
		}
	}
	ArithmeticMean = floor((double)Sum / (double)N + 0.5);
	

	sort(forSort.begin(), forSort.end());//중앙값 산출을 위해 sorting.
	 //숫자의 개수가 홀수일 때만 고려(문제의 조건).
	Median = forSort[forSort.size() / 2];
	
	int modeMax = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (forMode[i] > modeMax)
		{
			modeMax = forMode[i];
		}
	}
	
	for (int i = 0; i <= 8000; i++)
	{
		if (forMode[i] == modeMax)
		{
			if (i >= 4001)
			{
				forModePrint.push_back(i-4000);
			}
			else {
				forModePrint.push_back(-i);
			}
		}
	}
	sort(forModePrint.begin(), forModePrint.end()); //두번째로 작은 값 출력위해 sorting.
		if (forModePrint.size() >= 2)
		{
			Mode = forModePrint[1];
		}
		else {
			Mode = forModePrint[0];
		}

	Range = forSort.back()-forSort.front();
	cout << ArithmeticMean << endl << Median << endl << Mode << endl << Range << endl;
	return 0;
}