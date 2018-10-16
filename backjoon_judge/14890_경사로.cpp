#include <iostream>
using namespace std;

int map[101][101];

int main()
{
	//init
	int answer = 0;
	int heightWidth;
	int slopeLen;
	cin >> heightWidth >> slopeLen;
	for (int i = 0; i < heightWidth; i++)
		for (int j = 0; j < heightWidth; j++)
			cin >> map[i][j];

	//implement
	bool isInSlope;
	int inslopeCnt;
	int sameNumCnt;

	// ->���� üŷ.
	for (int i = 0; i < heightWidth; i++)
	{
		inslopeCnt = 0;
		sameNumCnt = 1;
		isInSlope = false;
		for (int j = 1; j < heightWidth; j++)
		{
			if (map[i][j] == map[i][j - 1])
			{
				if (isInSlope)
				{
					inslopeCnt--;
					if (inslopeCnt == 0)
						isInSlope = false;
				}
				else {
					sameNumCnt++;
				}
			}
			else if (map[i][j] - map[i][j - 1] == 1 && sameNumCnt >= slopeLen && !isInSlope) // ���̰� 1�̰� ������ �� ũ��.
			{
				sameNumCnt = 1;
			}
			else if (map[i][j] - map[i][j - 1] == -1) //���̰� 1�̰� ������ �� �۴�.
			{
				if (!isInSlope)
				{
					isInSlope = true;
					inslopeCnt = slopeLen - 1;
					if (inslopeCnt == 0)
						isInSlope = false;
					sameNumCnt = 0;
				}
				else {
					if (inslopeCnt > 0)
						break;
				}
			}
			else
				break;

			if (j == heightWidth - 1)
			{
				if (!isInSlope)
					answer++;
			}
		}
	}

	//�Ʒ����� üũ
	for (int i = 0; i < heightWidth; i++)
	{
		inslopeCnt = 0;
		sameNumCnt = 1;
		isInSlope = false;
		for (int j = 1; j < heightWidth; j++)
		{
			if (map[j][i] == map[j-1][i])
			{
				if (isInSlope)
				{
					inslopeCnt--;
					if (inslopeCnt == 0)
						isInSlope = false;
				}
				else {
					sameNumCnt++;
				}
			}
			else if (map[j][i] - map[j-1][i] == 1 && sameNumCnt >= slopeLen && !isInSlope) // ���̰� 1�̰� ������ �� ũ��.
			{
				sameNumCnt = 1;
			}
			else if (map[j][i] - map[j-1][i] == -1) //���̰� 1�̰� ������ �� �۴�.
			{
				if (!isInSlope)
				{
					isInSlope = true;
					inslopeCnt = slopeLen - 1;
					if (inslopeCnt == 0)
						isInSlope = false;
					sameNumCnt = 0;
				}
				else {
					if (inslopeCnt > 0)
						break;
				}
			}
			else
				break;

			if (j == heightWidth - 1)
			{
				if (!isInSlope)
					answer++;
			}
		}
	}

	cout << answer;
}