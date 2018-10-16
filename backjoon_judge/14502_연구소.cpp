#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//0은 빈칸 1은 벽 2는 바이러스.

int map[9][9]; //init map
int searchMap[9][9]; //forSearch tempMap
bool isVisit[9][9];
int nX[4] = { 0, -1, 0, 1 };
int nY[4] = { -1, 0, 1, 0 };
int width, height;
int answer = 0;
struct position {
	int y, x;
};

void bfs()
{
	int safeZoneCnt = 0;
	position nowPosition;
	queue<position>forSearchQueue;
	for(int i=0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (!isVisit[i][j] && searchMap[i][j] == 2)
			{
				forSearchQueue.push({ i,j });
				isVisit[i][j] = true;
			}
			while (!forSearchQueue.empty())
			{
				nowPosition = forSearchQueue.front();
				forSearchQueue.pop();
				for (int k = 0; k < 4; k++)
				{
					int nextY = nowPosition.y + nY[k];
					int nextX = nowPosition.x + nX[k];

					if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
					{
						if (!isVisit[nextY][nextX] && (searchMap[nextY][nextX] == 0 || searchMap[nextY][nextX] == 2))
						{
							forSearchQueue.push({ nextY, nextX });
							isVisit[nextY][nextX] = true;
							searchMap[nextY][nextX] = 2;
						}
					}
				}
			}
		}

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (searchMap[i][j] == 0)
				safeZoneCnt++;

	answer = max(answer, safeZoneCnt);
}

void copyMap()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			searchMap[i][j] = map[i][j];
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> height >> width;
	
	int forInsert;
	for(int i=0; i<height; i++)
		for (int j = 0; j < width; j++)
			cin >> map[i][j];

	for (int i = 0; i < height*width-2; i++)
	{
		for (int j = i+1; j < height*width-1; j++)
		{ 
			for (int k = j+1; k < height*width; k++)
			{
				copyMap();
				if (searchMap[i / width][i % width] == 0 && searchMap[j / width][j % width] == 0 && searchMap[k / width][k % width] == 0)
				{
					searchMap[i / width][i % width] = 1;
					searchMap[j / width][j % width] = 1;
					searchMap[k / width][k % width] = 1;
					memset(isVisit, 0, sizeof(isVisit));
					bfs();
				}
			}
		}
	}

	cout << answer;
}