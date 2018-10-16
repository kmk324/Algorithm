#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numArr;
int plMiMuDi[4];

int answerMax = -1000000000;
int answerMin = +1000000000;

void dfs(int nowNum, int numSeq)
{
	if (numSeq == numArr.size()) //base
	{
		answerMax = max(answerMax, nowNum);
		answerMin = min(answerMin, nowNum);
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			if (plMiMuDi[i])
			{
				if (i == 0)
				{
					plMiMuDi[i]--;
					dfs(nowNum + numArr[numSeq], numSeq+1);
					plMiMuDi[i]++;
				}
				if (i == 1)
				{
					plMiMuDi[i]--;
					dfs(nowNum - numArr[numSeq], numSeq+1);
					plMiMuDi[i]++;
				}
				if (i == 2)
				{
					plMiMuDi[i]--;
					dfs(nowNum * numArr[numSeq], numSeq+1);
					plMiMuDi[i]++;
				}
				if (i == 3)
				{
					plMiMuDi[i]--;
					dfs(nowNum / numArr[numSeq], numSeq+1);
					plMiMuDi[i]++;
				}
			}
		}
	}
}

int main()
{
	int numSize, num;
	cin >> numSize;
	for (int i = 0; i < numSize; i++)
	{
		cin >> num;
		numArr.push_back(num);
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> plMiMuDi[i];
	}

	dfs(numArr[0] , 1);
	cout << answerMax << endl;
	cout << answerMin << endl;
}