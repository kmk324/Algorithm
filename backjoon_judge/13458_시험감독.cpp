#include <iostream>
#include <vector>
using namespace std;
//주감독관수와 부감독관 수 최소 출력.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long answer = 0;
	int testRegionSize;
	vector <int> testerSize;
	int possibleMainSize, possibleSubSize;
	cin >> testRegionSize;
	int eachTester;
	for (int i = 0; i < testRegionSize; i++)
	{
		cin >> eachTester;
		testerSize.push_back(eachTester);
	}
	cin >> possibleMainSize >>possibleSubSize;

	for (int i = 0; i < testerSize.size(); i++)
	{
		testerSize[i] -= possibleMainSize;
		answer++;
		if (testerSize[i] > 0)
		{
			if (testerSize[i] % possibleSubSize == 0)
				answer += testerSize[i] / possibleSubSize;
			else
				answer += ((testerSize[i] / possibleSubSize) + 1);
		}
	}
	cout << answer;
}