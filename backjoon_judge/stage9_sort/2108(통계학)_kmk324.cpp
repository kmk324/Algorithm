#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// 2108 �����
//�ԷµǴ� ������ ���밪�� 4000�� ���� �ʴ´�. -> ������ -4000���� ����.
int forMode[8001] = { 0 }; //�ֺ�.

//sort(�迭�̸�+(�����ε���), (�迭�̸�)+(�������ε���+1))
//�ݿø� ���� �� ���̳ʽ� ���� �����ؾ� �ϹǷ� floor �Լ��� ����ؾ��Ѵ�.
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
			forMode[Num+4000]++; //1~4000 -> �ε��� 4001~8000.
		}
		else {
			forMode[abs(Num)]++; //0~-4000 -> �ε��� 0~4000.
		}
	}
	ArithmeticMean = floor((double)Sum / (double)N + 0.5);
	

	sort(forSort.begin(), forSort.end());//�߾Ӱ� ������ ���� sorting.
	 //������ ������ Ȧ���� ���� ���(������ ����).
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
	sort(forModePrint.begin(), forModePrint.end()); //�ι�°�� ���� �� ������� sorting.
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