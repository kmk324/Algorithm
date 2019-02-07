#include <iostream>
#include <queue>
using namespace std;

int heightWidth;
char realMap[101][101]; //'����'���� char�� �迭�� �ʱ�ȭ�ϸ� �ʱⰪ�� false�� ����.
char fakeMap[101][101];

struct position {
	int y, x;
};

//�� �� �� ��
int xDir[4] = { 1, 0, -1, 0 };
int yDir[4] = { 0, 1,  0, -1 };

bool isToVisit(char map[][101], char exChar, int nextY, int nextX) {
	if (nextX >= 0 && nextY >= 0 && nextX < heightWidth && nextY < heightWidth && map[nextY][nextX] == exChar)
		return true;
	else
		return false;
}

//�Լ������� ��������� realMap�迭�� �ݿ��Ǵ��� Ȯ�� -> �迭�̶� �ٲ��.
int solve(char map[][101]) //bfs.
{
	int areaCount = 0;
	queue <position> searchQueue;
	position nowPosition;
	int nextY, nextX;
	char exChar;

	for (int i = 0; i < heightWidth; i++)
	{
		for (int j = 0; j < heightWidth; j++)
		{
			if (map[i][j])
			{
				exChar = map[i][j];
				map[i][j] = 0;
				searchQueue.push({ i,j });
				areaCount++;
				while (!searchQueue.empty()) {
					nowPosition = searchQueue.front();
					searchQueue.pop();
					for (int k = 0; k < 4; k++)
					{
						nextY = nowPosition.y + yDir[k];
						nextX = nowPosition.x + xDir[k];
						if (isToVisit(map, exChar, nextY, nextX))
						{
							searchQueue.push({ nextY,nextX });
							map[nextY][nextX] = 0;
						}
					}
				}
			}
		}
	}
	return areaCount;
}

int main()
{
	int realAreaCount;
	int fakeAreaCount;

	cin >> heightWidth;
	
	//init.
	for (int i = 0; i < heightWidth; i++)
	{
		for (int j = 0; j < heightWidth; j++) {
			cin >> realMap[i][j];
			if (realMap[i][j] == 'G')
			{
				fakeMap[i][j] = 'R';
			}
			else {
				fakeMap[i][j] = realMap[i][j];
			}
		}
	}
	realAreaCount = solve(realMap);
	fakeAreaCount = solve(fakeMap);

	cout << realAreaCount << " " << fakeAreaCount;
}