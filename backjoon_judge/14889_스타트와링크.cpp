#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int map[21][21];
vector<bool> isSelected;

int main()
{
	int playerSize;
	cin >> playerSize;

	for (int i = 1; i <= playerSize; i++)
	{
		if (i <= playerSize / 2)
			isSelected.push_back(0);
		else
			isSelected.push_back(1);

		for (int j = 1; j <= playerSize; j++)
		{
			cin >> map[i][j];
		}
	}

	int answerMin = 217478400;
	int sumA, sumB;
	do {
		sumA = 0;
		sumB = 0;
		for (int i = 0; i < isSelected.size(); i++)
		{
			for (int j = i + 1; j < isSelected.size(); j++)
			{
				if (isSelected[i] && isSelected[j])
				{
					sumA += map[i + 1][j + 1];
					sumA += map[j + 1][i + 1];
				}
				else if (!isSelected[i] && !isSelected[j]) {
					sumB += map[i + 1][j + 1];
					sumB += map[j + 1][i + 1];
				}
			}
		}
		answerMin = min(answerMin, abs(sumA - sumB));
	} while (next_permutation(isSelected.begin(), isSelected.end()));

	cout << answerMin;
}
