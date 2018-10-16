#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//bfs로 풀다가 fail.
//문제 분석을 충분히 한 후 구현하자.
//백트래킹 필요한지 확실히 숙지하고 풀이에 들어가야함.

bool isVisitAlpha[100]; //A~Z - 65~90
char board[22][22];
int answer = 0;
int nX[4] = { 0,-1, 0,1 };
int nY[4] = {-1, 0, 1,0 };

void dfs(int nowX, int nowY, int nowMax )
{
	answer = max(nowMax, answer);
	for (int i = 0; i < 4; i++)
	{
		int nextX = nowX + nX[i];
		int nextY = nowY + nY[i];
		if (!isVisitAlpha[board[nextX][nextY]] && board[nextX][nextY])
		{
			isVisitAlpha[board[nextX][nextY]] = true;
			dfs(nextX, nextY, nowMax + 1);
			isVisitAlpha[board[nextX][nextY]] = false;
		}
	}
}

int main()
{
	int boardH, boardW;
	cin >> boardH >> boardW;
	for(int i = 1; i<= boardH; i++)
		for (int j = 1; j <= boardW; j++)
			cin >> board[i][j];
	isVisitAlpha[board[1][1]] = true;
	dfs(1,1,1);
	cout << answer;
}