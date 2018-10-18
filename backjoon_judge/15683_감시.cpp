#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//��Ž
//�簢������ ���� 64�� ���� �� ����.
//cctv�� cctv�� ����� �� �ִ�.

//1�� 4�� �ִٸ�
//0000���� 0001... ~ 4444���� ��
// 1 0 : 1~4
// 1 1: 1~4
// 1 2: 1~4
// 1 3: 1~4

//�߻� : ��� cctv�� ������ ���¸� ������ �� -> �簢���� �ּҰ� �ǽð� ����

int map[9][9];
int copyMap[9][9];
struct cctv {
	int y, x;
	int cctvNum, cctvDir;
};
vector<cctv> cctvPosition;
int nX[4] = { 1,0,-1,0 };
int nY[4] = { 0,-1,0,1 };


int height, width;
int answerMin = 65;
int CantSeeZoneCnt;

void copy()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			copyMap[i][j] = map[i][j];
}

void cctv1Search(int y, int x, int dir)
{
	int nowY = y;
	int nowX = x;
	while (1)
	{
		int nextY = nowY + nY[dir];
		int nextX = nowX + nX[dir];

		//Ž�������� �� �ΰ�?
		if (nextY < height && nextY >= 0 && nextX >= 0 && nextX < width)
		{
			nowY = nextY;
			nowX = nextX;
			if (copyMap[nextY][nextX] != 6)
			{
				if (copyMap[nextY][nextX] == 0)
					copyMap[nextY][nextX] = 1;
				else
					continue;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}
}

void cctv2Search(cctv nowSearchCctv)
{
	if (nowSearchCctv.cctvDir < 2) //0,1 <->
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 0);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 2);
	}
	else //���Ʒ�
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 1);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 3);
	}
}
void cctv3Search(cctv nowSearchCctv)
{
	if (nowSearchCctv.cctvDir == 0)
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 3);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 0);
	}
	else if (nowSearchCctv.cctvDir == 1)
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 0);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 1);
	}
	else if (nowSearchCctv.cctvDir == 2)
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 1);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 2);
	}
	else {
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 2);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 3);
	}
}
void cctv4Search(cctv nowSearchCctv)
{
	if (nowSearchCctv.cctvDir == 0)
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 2);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 3);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 0);
	}
	else if (nowSearchCctv.cctvDir == 1)
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 3);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 0);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 1);
	}
	else if (nowSearchCctv.cctvDir == 2)
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 0);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 1);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 2);
	}
	else {
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 1);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 2);
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 3);
	}
}
void cctv5Search(cctv nowSearchCctv)
{
	cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 0);
	cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 1);
	cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 2);
	cctv1Search(nowSearchCctv.y, nowSearchCctv.x, 3);
}

void search(cctv nowSearchCctv)
{
	if (nowSearchCctv.cctvNum == 1)
	{
		cctv1Search(nowSearchCctv.y, nowSearchCctv.x, nowSearchCctv.cctvDir);
	}
	else if (nowSearchCctv.cctvNum == 2)
	{
		cctv2Search(nowSearchCctv);
	}
	else if (nowSearchCctv.cctvNum == 3)
	{
		cctv3Search(nowSearchCctv);
	}
	else if (nowSearchCctv.cctvNum == 4)
	{
		cctv4Search(nowSearchCctv);
	}
	else// cctvNum=5
	{
		cctv5Search(nowSearchCctv);
	}
}

void dfs(int nowCctvSeq)
{
	if (nowCctvSeq == cctvPosition.size()) //��� cctv�� ���� ���� �Ϸ�.
	{
		//��Ȳ ����.
		copy();
		CantSeeZoneCnt = 0;
		for (int i = 0; i < cctvPosition.size(); i++)
		{
			search(cctvPosition[i]);
		}

		//������ ��Ȳ �� Ž���ϸ鼭 �簢���밪+= && �ּҰ� ����.
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (copyMap[i][j] == 0)
					CantSeeZoneCnt++;

		answerMin = min(answerMin, CantSeeZoneCnt);
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			cctvPosition[nowCctvSeq].cctvDir = i;
			dfs(nowCctvSeq + 1);
		}
	}
}

int main()
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) //cctv��ġ���� ����.
			{
				cctvPosition.push_back({ i,j,map[i][j],0 }); //y,x cctvnum, �ʱ� ����
			}
		}
	dfs(0);
	cout << answerMin;
}