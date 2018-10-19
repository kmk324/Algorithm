#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//2��15
//TC pass 1�ð��ҿ�.
//����� 40��. �־��� ���Ǻ����� X��� �������� �ƴϴ�! �־��� ���Ǻ����� Y��� �������̾ƴϴ�!

//1<=height, width <=20
//�ֻ��� �ʱ���ġ 0<=x <=height-1, 0<= =y <=width-1
//��1 ��2 ��3 ��4 fixed. ����� �̵�����
//1<=commandSize <=1000
// �ֻ��� ����ĭ �׻� 0 //�ʱⰪ ��� ���� 0
//�ʱ� ���� ����, 3
//0���� 1���� 2���� 3���� 4���� 5�Ʒ� fixed.

//�淮ȭ ���������� �������� ���� �Լ� 4���� ����.
//��� 4 : 4->5 5->1 0->4 1->0 && y,x (1,0) �������� roll�̵�.
//��� 3 : 5->4 1->5 0->1 4->0 && y,x (-1,0) �������� roll
//��� 2 : 3->5 2->0 0->3 5->2 && y,x (0,-1) �������� roll.
//��� 1 : 5->3 0->2 3->0 2->5 && y,x (0,1)//�������� roll.

int dice[6];//0���� 1���� 2���� 3���� 4���� 5�Ʒ� fixed.
int mY[4] = { 0,0,-1,1 }; //�����ϳ� ���� ����.
int mX[4] = { 1,-1,0,0 };
int height, width;
int map[21][21];
vector<int> command;

//��� 1 : 5->3 0->2 3->0 2->5 && y,x (0,1)//�������� roll.
void command1()
{
	int temp0;
	temp0 = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = temp0;
}

//��� 2 : 3->5 2->0 0->3 5->2 && y,x (0,-1) �������� roll.
void command2()
{
	int temp0;
	temp0 = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = temp0;
}

//��� 3 : 5->4 1->5 0->1 4->0 && y,x (-1,0) �������� roll
void command3()
{
	int temp0;
	temp0 = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = temp0;
}

//��� 4 : 4->5 5->1 0->4 1->0 && y,x (1,0) �������� roll�̵�.
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
		//���� nextY, nextX ��ǥ�� ���� Ȯ��.
		//�̵������� ���ΰ�?
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

			if (map[nowY][nowX]) //0�̾ƴϸ�
			{
				dice[5] = map[nowY][nowX];//ĭ�� �������ִ°��� �ٴڸ����� ����.
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