#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isVisit[100001];
int positionCnt[100001];
int startP, endP;

int moveCnt = 0;

void bfs(int start)
{
	queue<int>forSearch;
	forSearch.push(start);
	isVisit[start] = true;
	int nowPotition;
	while (!forSearch.empty())
	{
		nowPotition = forSearch.front();
		forSearch.pop();
		if (nowPotition == endP)
		{
			moveCnt = positionCnt[nowPotition];
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == 0 && nowPotition+1 <=100000)
			{
				if (!isVisit[nowPotition + 1])
				{
					forSearch.push(nowPotition + 1);
					isVisit[nowPotition + 1] = true;
					positionCnt[nowPotition + 1] = positionCnt[nowPotition] + 1;
				}
			}
			else if (i == 1 && nowPotition-1 >=0)
			{
				if (!isVisit[nowPotition - 1])
				{
					forSearch.push(nowPotition - 1);
					isVisit[nowPotition - 1] = true;
					positionCnt[nowPotition - 1] = positionCnt[nowPotition] + 1;
				}
			}
			else {
				if (nowPotition * 2 <= 100000)
				{
					if (!isVisit[nowPotition * 2])
					{
						forSearch.push(nowPotition * 2);
						isVisit[nowPotition * 2] = true;
						positionCnt[nowPotition * 2] = positionCnt[nowPotition] + 1;
					}
				}
			}
		}
	}

}

int main()
{	
	cin >> startP >> endP;
	bfs(startP);
	cout << moveCnt;
}