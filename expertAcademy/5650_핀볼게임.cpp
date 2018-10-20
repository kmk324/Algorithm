#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//�ɺ�����
//5 <= heightWidth <=100 
int map[101][101];
int heightWidth;
int answer;
int score;
int mY[4] = { -1, 1, 0, 0 }; //�����¿�
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

	for (int i = 0; i < 4; i++)//������ ��ġ���� �׹������� ���� �����ϴ�.
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
				//���� ��ġ�� ���� �����, �����ʰ� ���⸸ �ݴ��. ����++
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
				//���� ����� �ʰ�, ���� ��ġ�� 0�϶�
				else if(map[nextY][nextX] ==0)
				{ 
					nowY = nextY;
					nowX = nextX;
				}
				//���� ��ġ�� ����̸� ���� �ʰ�, ���⸸ �ٲ���. ����++
				else if (map[nextY][nextX] >=1 && map[nextY][nextX] <=5 )
				{
					score++;
					//1�� ����̸�
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
					//2�� ����̸�
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
					//3�� ����̸�
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
					//4�� ����̸�
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
					//5�� ����̸�
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
				//���� ��ġ�� ��Ȧ�̸� �ش� ��Ȧ�� �ݴ������� �̵�.
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
				//���� ��ġ�� ��Ȧ�̸� break. ����
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