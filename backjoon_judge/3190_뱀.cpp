#include <iostream>
#include <queue>
using namespace std;
//8시30분
//1시간 소요.

// 2<=heigtwidth <=100
// 0<= appleSize <= 100 //사과는2로 매핑
// 뱀은 1로 매핑
// 시작 위치는 1,1로 둔다.
// D는 오른쪽으로 L은 왼쪽으로, D는 1로 L은2로 매핑.
int map[101][101];
int heightWidth;
int mY[4] = { 0, -1, 0,1 }; //동 북 서 남
int mX[4] = { 1,  0,-1,0 }; //동 북 서 남
struct Position {
	int y, x;
};

int second = 0;
int appleSize;
int commandSize;
char command[10001]; //x초후 명령 

queue <Position> snakePos;

void solve()
{
	int nowY = 1;
	int nowX = 1;
	int nextY, nextX;
	int dir = 0; //초기 방향.
	snakePos.push({ 1,1 });
	map[1][1] = 1;
	
	while (1)
	{
		second++;
		nextY = nowY + mY[dir];
		nextX = nowX + mX[dir];
		//갈 수 있는 곳인가. 갈 수 없다면 break;
		if (nextY >= 1 && nextY <= heightWidth && nextX >= 1 && nextX <= heightWidth && map[nextY][nextX] != 1)
		{
			if (map[nextY][nextX] != 2) //사과가 없다면.
			{
				map[snakePos.front().y][snakePos.front().x] = 0;
				snakePos.pop();	
			}
			map[nextY][nextX] = 1;
			snakePos.push({ nextY,nextX });
			nowY = nextY;
			nowX = nextX;
			
			if (command[second] == 'L') //동북서남 순.
			{
				dir += 1;
				if (dir == 4)
					dir = 0;
			}
			//0동 1북 2서 3남
			else if (command[second] == 'D') //동남서북
			{
				dir -= 1;
				if (dir == -1)
					dir = 3;
			}
		}
		else { //갈 수 없다. (내 몸이거나 경계밖이다.)
			break;
		}
	}
}

int main()
{
	cin >> heightWidth;
	cin >> appleSize;
	
	int appleY, appleX;
	for (int i = 0; i < appleSize; i++)
	{
		cin >> appleY >> appleX;
		map[appleY][appleX] = 2;
	}
	cin >> commandSize;
	
	int commandSecnd;
	char commandChar;
	for (int i = 0; i < commandSize; i++)
	{
		cin >> commandSecnd >> commandChar;
		command[commandSecnd] = commandChar;
	}

	solve();
	cout << second;
}