#include <iostream>
using namespace std;

//*방향매핑 실수 주의*

int height, width;
int map[51][51];
int nY[5] = { -1,  0, 1, 0 }; //0 1 2 3 북 동 남 서
int nX[5] = { 0, 1, 0,-1 }; //다음 탐색 순서 0->3 1->0 2->1 3->2
//후진 0->2 1->3 2->0 3->1
//빈칸 0, 벽 1, 청소한공간 2로 하자.
int answer = 0;
void solve(int y, int x, int dir)
{
	int nowY = y;
	int nowX = x;
	int searchCnt = 0;

	map[nowY][nowX] = 2; //1.현재 위치를 청소한다.
	answer++;
	while (1)
	{
		dir = dir -1;
		if (dir == -1)
			dir = 3;

		int nextY = nowY + nY[dir];
		int nextX = nowX + nX[dir];

		if (map[nextY][nextX] == 0)//
		{
			searchCnt = 0;
			map[nextY][nextX] = 2;
			nowY = nextY;
			nowX = nextX;
			answer++;
		}
		else {
			searchCnt++;
			if (searchCnt == 4)
			{
				if (dir <= 1)
				{
					nextY = nowY + nY[dir + 2];
					nextX = nowX + nX[dir + 2];
				}
				else
				{
					nextY = nowY + nY[dir - 2];
					nextX = nowX + nX[dir - 2];
				}

				if (map[nextY][nextX] == 2)
				{
					searchCnt = 0;
					nowY = nextY;
					nowX = nextX;
				}
				else {
					break;
				}
			}
		}
	}
}

int main()
{

	cin >> height >> width;

	int nowPosY, nowPosX, nowDir;
	cin >> nowPosY >> nowPosX >> nowDir;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cin >> map[i][j];

	solve(nowPosY, nowPosX, nowDir);
	cout << answer;
}