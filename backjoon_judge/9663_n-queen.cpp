#include <iostream>
using namespace std;

int n;
int queenCnt = 0;
int answer = 0;
bool impossibleHeight[17];
bool impossibleDiag1[50];
bool impossibleDiag2[50];

void dfs(int queenCnt)
{
	if (queenCnt == n)
		answer++;
	else {
		for (int j = 0; j < n; j++)
		{
			if (!impossibleHeight[j] && !impossibleDiag1[queenCnt+j] && !impossibleDiag2[n-j+queenCnt-1 ])
			{
				impossibleHeight[j] = impossibleDiag1[queenCnt + j] = impossibleDiag2[n - j + queenCnt - 1 ]= 1;
				
				dfs(queenCnt +1);
				
				impossibleHeight[j] = impossibleDiag1[queenCnt + j] = impossibleDiag2[n - j + queenCnt - 1] = 0;
			}
		}
	}
}
int main()
{
	cin >> n;
	dfs(0);
	cout << answer;
}