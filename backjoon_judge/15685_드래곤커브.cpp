#include <iostream>
#include <vector>
using namespace std;

/*
Ǯ�� �ı�
�ҿ�ð� �� 1�ð�.
 nextdir = nowDir+1%4 (������ �켱���� ����!)
 nextdir = (nowDir+1) %4 ������ �켱���� ������ �̷��� �����־�� �ϴµ�
 ù�� ó�� �����ߴٰ� ������ϴµ� 30�� �ҿ��ߴ�.
 */

//�˰��� ����
//�巡�� Ŀ�� ��ŷ�س���, �� ���鼭 ���� ����.
//100 x 100 ��.
//�巡��Ŀ��� 0~10����, 1~20��.
//d�� ���� ���� 0�� 1�� 2�� 3�� fixed. nextdir = nowDir+1%4 (������ �켱���� ����!)
//�巡�� Ŀ��� �Դ� ���⸸ ����س��Ҵٸ� �� ������ ������ ��ġ���� �׷����� �� �ִ�.!

//0���� ���۹������� +1 ex)��
//1���� 0���븶���������� +1 ex)��������
//2���� ���� ���� //�ϼ���Ʈ ���ϼ�Ʈ.
//3���� ���ϼ��� ��������
//4���� ���ϼ��� ��������+ ��������

//2���� �巹�� Ŀ�긦 �����->for(3��) �ʱ⿡ ����ִ� �������� �̵�, 
//0����, ����ִ� �������� �̵�&& ���Ϳ� ���� �߰�,
//1����, ����ִ� ����+1�� �̵� && ���Ϳ� (����+1) �߰�.
//2����, 1���� ������������. ����ִ� ����(2���������)���� �ϳ���(�ε��� �ڿ�������) �ش���� +1�������ΰ��鼭 �̵� && ���Ϳ� ���� �߰�.

int answer = 0;
int map[101][101];
int mY[4] = { 0,-1,0,1 };
int mX[4] = { 1,0,-1,0 };
vector<int> exDir;

void makeCurve(int sX, int sY, int sDir, int generation)
{
	int nowX, nowY, nowDir, exDirSize;
	exDir.clear();
	exDir.push_back(sDir);
	//0���� ����
	map[sY][sX] = 1;
	nowY = sY + mY[sDir];
	nowX = sX + mX[sDir];
	map[nowY][nowX] = 1;

	//generation 0�̸� ���� �ʴ´�.
	for (int i = 0; i < generation; i++)
	{
		exDirSize = exDir.size();
		for (int j = exDirSize-1; j>=0; j--) //exDirĿ�������� ������ ���� �����.
		{
			nowDir = (exDir[j] + 1)% 4;
			nowY = nowY + mY[nowDir];
			nowX = nowX + mX[nowDir];
			map[nowY][nowX] = 1;
			exDir.push_back(nowDir);
		}
	}
}

void squareCnt()
{
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				answer++;
		}
	}
}

int main()
{
	int curveSize, startX,startY, startDir, generation;
	cin >> curveSize;
	for (int i = 0; i < curveSize; i++)
	{
		cin >> startX >> startY >> startDir >> generation;
		makeCurve(startX, startY, startDir, generation);
	}
	squareCnt();

	cout << answer;
}