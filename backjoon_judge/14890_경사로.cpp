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

	// ->방향 체킹.
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
			else if (map[i][j] - map[i][j - 1] == 1 && sameNumCnt >= slopeLen && !isInSlope) // 차이가 1이고 다음게 더 크다.
			{
				sameNumCnt = 1;
			}
			else if (map[i][j] - map[i][j - 1] == -1) //차이가 1이고 다음게 더 작다.
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

	//아래방향 체크
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
			else if (map[j][i] - map[j-1][i] == 1 && sameNumCnt >= slopeLen && !isInSlope) // 차이가 1이고 다음게 더 크다.
			{
				sameNumCnt = 1;
			}
			else if (map[j][i] - map[j-1][i] == -1) //차이가 1이고 다음게 더 작다.
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