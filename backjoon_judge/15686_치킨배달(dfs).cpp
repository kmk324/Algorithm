#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//시간초과난 코드임. ->해결
//dfs 백트래킹으로 풀기. ->해결
//branch and bound 추가.

int city[51][51];
bool isVisit[51][51];
vector<int> chickDistance[51][51];

struct position {
	int y, x;
};

vector<position>chickStoPosition;
int minDistance = 2147483647;
int chickStoreSize;
int heightWidth;
int chickStoreSizeInMap=0;

int localMinDistance;
void dfs(position nowPosition, int selectedStCnt, int remainChickStore)
{	
	if (selectedStCnt == chickStoreSize )
	{
		localMinDistance = 0;
		for(int i=1; i<=heightWidth; i++)
			for(int j=1; j<=heightWidth; j++)
				if (city[i][j] == 1)
				{
					int one2oneDist = 2147483647;
					for (unsigned int k = 0; k < chickStoPosition.size(); k++) 
					{
						one2oneDist = min(one2oneDist, abs(i - chickStoPosition[k].y) + abs(j - chickStoPosition[k].x));
					}
					localMinDistance += one2oneDist;
				}
		minDistance = min(minDistance, localMinDistance);
	}
	else {
		if (!remainChickStore + selectedStCnt >= chickStoreSize)
			return;
		bool isfirstLoop = true;
		for (int i = nowPosition.y; i <= heightWidth &&isfirstLoop; i++)
		{
			for (int j=1; j <= heightWidth; j++)
			{
				if (city[i][j] == 2 && !isVisit[i][j] )
				{
					isVisit[i][j] = true; 
					chickStoPosition.push_back({ i,j });
					dfs({ i,j }, selectedStCnt + 1, remainChickStore -1);
					chickStoPosition.pop_back();
					dfs({ i,j }, selectedStCnt, remainChickStore -1);
					isVisit[i][j] = false;
					isfirstLoop = false;
					break;
				}

			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> heightWidth >> chickStoreSize;

	for (int i = 1; i <= heightWidth; i++)
		for (int j = 1; j <= heightWidth; j++)
		{
			cin >> city[i][j];
			if(city[i][j]==2)
			chickStoreSizeInMap++;
		}

	dfs({ 1, 1 }, 0, chickStoreSizeInMap);

	cout << minDistance;
}