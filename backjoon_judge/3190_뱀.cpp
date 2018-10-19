#include <iostream>
#include <queue>
using namespace std;
//8��30��
//1�ð� �ҿ�.

// 2<=heigtwidth <=100
// 0<= appleSize <= 100 //�����2�� ����
// ���� 1�� ����
// ���� ��ġ�� 1,1�� �д�.
// D�� ���������� L�� ��������, D�� 1�� L��2�� ����.
int map[101][101];
int heightWidth;
int mY[4] = { 0, -1, 0,1 }; //�� �� �� ��
int mX[4] = { 1,  0,-1,0 }; //�� �� �� ��
struct Position {
	int y, x;
};

int second = 0;
int appleSize;
int commandSize;
char command[10001]; //x���� ��� 

queue <Position> snakePos;

void solve()
{
	int nowY = 1;
	int nowX = 1;
	int nextY, nextX;
	int dir = 0; //�ʱ� ����.
	snakePos.push({ 1,1 });
	map[1][1] = 1;
	
	while (1)
	{
		second++;
		nextY = nowY + mY[dir];
		nextX = nowX + mX[dir];
		//�� �� �ִ� ���ΰ�. �� �� ���ٸ� break;
		if (nextY >= 1 && nextY <= heightWidth && nextX >= 1 && nextX <= heightWidth && map[nextY][nextX] != 1)
		{
			if (map[nextY][nextX] != 2) //����� ���ٸ�.
			{
				map[snakePos.front().y][snakePos.front().x] = 0;
				snakePos.pop();	
			}
			map[nextY][nextX] = 1;
			snakePos.push({ nextY,nextX });
			nowY = nextY;
			nowX = nextX;
			
			if (command[second] == 'L') //���ϼ��� ��.
			{
				dir += 1;
				if (dir == 4)
					dir = 0;
			}
			//0�� 1�� 2�� 3��
			else if (command[second] == 'D') //��������
			{
				dir -= 1;
				if (dir == -1)
					dir = 3;
			}
		}
		else { //�� �� ����. (�� ���̰ų� �����̴�.)
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