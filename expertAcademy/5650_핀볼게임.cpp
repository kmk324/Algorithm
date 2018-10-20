#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//핀볼게임
//5 <= heightWidth <=100 
int map[101][101];
int heightWidth;
int answer;
int score;
int mY[4] = { -1, 1, 0, 0 }; //상하좌우
int mX[4] = {  0, 0,-1, 1 };

struct position {
	int y, x;
};

vector<position>warmHole[11];

void gameStart(int sY, int sX)
{
	int nowY = sY;
	int nowX = sX;
	int nextY, nextX;
	int dir;

	for (int i = 0; i < 4; i++)//정해진 위치에서 네방향으로 진행 가능하다.
	{
		score = 0;
		dir = i;
		nowY = sY;
		nowX = sX;
		while (1)
		{
			nextY = nowY + mY[dir];
			nextX = nowX + mX[dir];
			
			if ( !(nextY == sY && nextX == sX))
			{
				//다음 위치가 맵을 벗어나면, 가지않고 방향만 반대로. 점수++
				if (nextY <= 0 || nextY > heightWidth || nextX <= 0 || nextX > heightWidth)
				{
					if (dir == 0 || dir == 2)
						dir += 1;
					else
						dir -= 1;
					score++;
					nowY = nextY;
					nowX = nextX;
				}
				//맵을 벗어나지 않고, 다음 위치가 0일때
				else if(map[nextY][nextX] ==0)
				{ 
					nowY = nextY;
					nowX = nextX;
				}
				//다음 위치가 블록이면 가지 않고, 방향만 바꿔줌. 점수++
				else if (map[nextY][nextX] >=1 && map[nextY][nextX] <=5 )
				{
					score++;
					//1번 블록이면
					if (map[nextY][nextX] == 1)
					{
						if (dir == 0)
							dir = 1;
						else if (dir == 1)
							dir = 3;
						else if (dir == 2)
							dir = 0;
						else {
							dir = 2;
						}
					}
					//2번 블록이면
					else if (map[nextY][nextX] == 2)
					{
						if (dir == 0)
							dir = 3;
						else if (dir == 1)
							dir = 0;
						else if (dir == 2)
							dir = 1;
						else {
							dir = 2;
						}
					}
					//3번 블록이면
					else if (map[nextY][nextX] == 3)
					{
						if (dir == 0)
							dir = 2;
						else if (dir == 1)
							dir = 0;
						else if (dir == 2)
							dir = 3;
						else {
							dir = 1;
						}
					}
					//4번 블록이면
					else if (map[nextY][nextX] == 4)
					{
						if (dir == 0)
							dir = 1;
						else if (dir == 1)
							dir = 2;
						else if (dir == 2)
							dir = 3;
						else {
							dir = 0;
						}
					}
					//5번 블록이면
					else {
						if (dir == 0)
							dir = 1;
						else if (dir == 1)
							dir = 0;
						else if (dir == 2)
							dir = 3;
						else {
							dir = 2;
						}
					}
					nowY = nextY;
					nowX = nextX;
				}
				//다음 위치가 웜홀이면 해당 웜홀의 반대편으로 이동.
				else if (map[nextY][nextX] >= 6)
				{
					if (nextY == warmHole[map[nextY][nextX]][0].y && nextX == warmHole[map[nextY][nextX]][0].x)
					{
						nowY = warmHole[map[nextY][nextX]][1].y;
						nowX = warmHole[map[nextY][nextX]][1].x;
					}
					else {
						nowY = warmHole[map[nextY][nextX]][0].y;
						nowX = warmHole[map[nextY][nextX]][0].x;
					}
				}
				//다음 위치가 블랙홀이면 break. ㄹㄹ
				else
				{
					break;
				}
			}
			else {
				break;
			}
		}
		answer = max(answer, score);
	}
}

int main()
{
	int tcSize;
	cin >> tcSize;
	for (int test_case = 1; test_case <= tcSize; ++test_case)
	{
		//init.
		for (int i = 0; i < 11; i++)
			warmHole[i].clear();
		answer = 0;
		score = 0;
		cin >> heightWidth;
		for (int i = 1; i <= heightWidth; i++)
		{
			for (int j = 1; j <= heightWidth; j++)
			{
				cin >> map[i][j];
				if (map[i][j] >= 6)
					warmHole[map[i][j]].push_back({ i,j });
			}
		}

		//implement
		for (int i = 1; i <= heightWidth; i++)
			for (int j = 1; j <= heightWidth; j++)
				if (map[i][j] == 0)
					gameStart(i,j);
	
		cout <<'#'<<test_case <<' '<< answer << endl;
	}
	return 0;
}