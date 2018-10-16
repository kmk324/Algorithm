#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

bool feild[50][50];
int nX[4] = {-1,  0, 1, 0 };
int nY[4] = { 0, -1, 0, 1 };
int answer = 0;
struct position{
	int x, y;
};

queue <position>searchQueue;

void bfs(int feildWidth, int feildHeight) {
	position nowPosition;
	for(int i=0; i<feildWidth; i++)
		for (int j = 0; j < feildHeight; j++)
		{
			if (feild[i][j])
			{
				searchQueue.push({ i, j });
				feild[i][j] = 0;
				answer++;
				while (!searchQueue.empty())
				{
					nowPosition = searchQueue.front();
					searchQueue.pop();
					for (int i = 0; i < 4; i++)
					{
						int nextX = nowPosition.x + nX[i];
						int nextY = nowPosition.y + nY[i];
						if (nextX >= 0 && nextX <= 49 && nextY >= 0 && nextY <= 49)
						{
							if (feild[nextX][nextY])
							{
								searchQueue.push({ nextX,nextY });
								feild[nextX][nextY] = 0;
							}
						}
					}
				}
			}
		}
}
int main()
{
	int testSize;
	int fieldWidth, fieldHeight, cabbageSize;
	int cabbageX, cabbageY;
	cin >> testSize;
	for (int i = 0; i < testSize; i++)
	{
		//testCase init
		answer = 0;
		memset(feild, 0, sizeof(feild));
		cin >> fieldWidth >> fieldHeight >> cabbageSize;
		for (int j = 0; j < cabbageSize; j++)
		{
			cin >> cabbageX >> cabbageY;
			feild[cabbageX][cabbageY] = 1;
		}
		//bfs
		bfs(fieldWidth, fieldHeight);
		cout << answer << endl;
	}
}