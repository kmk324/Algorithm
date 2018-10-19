#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//2시15
//TC pass 1시간소요.
//디버깅 40분. 주어진 조건변수가 X라고 가로축이 아니다! 주어진 조건변수가 Y라고 세로축이아니다!

//1<=height, width <=20
//주사위 초기위치 0<=x <=height-1, 0<= =y <=width-1
//동1 서2 북3 남4 fixed. 명령의 이동방향
//1<=commandSize <=1000
// 주사위 놓는칸 항상 0 //초기값 모든 면이 0
//초기 방향 동쪽, 3
//0이위 1북쪽 2동쪽 3서쪽 4남쪽 5아래 fixed.

//경량화 가능하지만 가독성을 위해 함수 4개로 나눔.
//명령 4 : 4->5 5->1 0->4 1->0 && y,x (1,0) 남쪽으로 roll이동.
//명령 3 : 5->4 1->5 0->1 4->0 && y,x (-1,0) 북쪽으로 roll
//명령 2 : 3->5 2->0 0->3 5->2 && y,x (0,-1) 서쪽으로 roll.
//명령 1 : 5->3 0->2 3->0 2->5 && y,x (0,1)//동쪽으로 roll.

int dice[6];//0이위 1북쪽 2동쪽 3서쪽 4남쪽 5아래 fixed.
int mY[4] = { 0,0,-1,1 }; //동서북남 으로 정함.
int mX[4] = { 1,-1,0,0 };
int height, width;
int map[21][21];
vector<int> command;

//명령 1 : 5->3 0->2 3->0 2->5 && y,x (0,1)//동쪽으로 roll.
void command1()
{
	int temp0;
	temp0 = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = temp0;
}

//명령 2 : 3->5 2->0 0->3 5->2 && y,x (0,-1) 서쪽으로 roll.
void command2()
{
	int temp0;
	temp0 = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = temp0;
}

//명령 3 : 5->4 1->5 0->1 4->0 && y,x (-1,0) 북쪽으로 roll
void command3()
{
	int temp0;
	temp0 = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = temp0;
}

//명령 4 : 4->5 5->1 0->4 1->0 && y,x (1,0) 남쪽으로 roll이동.
void command4()
{
	int temp0;
	temp0 = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = temp0;
}

void solve(int nY, int nX)
{
	int nowY = nY;
	int nowX = nX;
	int nextY, nextX;
	for (int i = 0; i < command.size(); i++)
	{
		nextY = nowY + mY[command[i] - 1];
		nextX = nowX + mX[command[i] - 1];
		//먼저 nextY, nextX 좌표의 값을 확인.
		//이동가능한 곳인가?
		if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
		{
			nowY = nextY;
			nowX = nextX;
			if (command[i] == 1)
				command1();
			else if (command[i] == 2)
				command2();
			else if (command[i] == 3)
				command3();
			else
				command4();

			if (map[nowY][nowX]) //0이아니면
			{
				dice[5] = map[nowY][nowX];//칸에 쓰여져있는값이 바닥면으로 복사.
				map[nowY][nowX] = 0;
			}
			else {
				map[nowY][nowX] = dice[5];
			}
			cout << dice[0] << endl;
		}
	}
}
int main()
{
	//init.
	int startX, startY, commandSize, forInsertCommand;
	cin >> height >> width >> startY >> startX >> commandSize;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cin >> map[i][j];
	for (int i = 0; i < commandSize; i++)
	{
		cin >> forInsertCommand;
		command.push_back(forInsertCommand);
	}
	//go.
	solve(startY, startX);
}