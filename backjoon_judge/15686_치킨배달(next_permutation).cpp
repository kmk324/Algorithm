#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int city[51][51];
struct position {
	int y, x;
};
int heightWidth;
int chickStoreSize;
vector<position>chickStoPosition;
vector<int> selectedStore;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> heightWidth >> chickStoreSize;

	for (int i = 1; i <= heightWidth; i++)
		for (int j = 1; j <= heightWidth; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 2)
			{
				chickStoPosition.push_back({ i,j });
				selectedStore.push_back(0);
			}
		}

	for (int i = 0; i < chickStoreSize; i++)
		selectedStore[i] = 1;

	sort(selectedStore.begin(), selectedStore.end());

	int globalSumMin = INT_MAX;
	int localSumMin;
	int one2oneDistMin, one2oneDist;
	
	do {
		localSumMin = 0;
		for(int i = 1; i<=heightWidth; i++)
			for (int j = 1; j <= heightWidth; j ++ )
			{
				if (city[i][j] == 1)
				{
					one2oneDistMin = INT_MAX;
					for (int k = 0; k < chickStoPosition.size(); k++)
					{	
						if (selectedStore[k])
						{
							one2oneDist = abs(i - chickStoPosition[k].y) + abs(j - chickStoPosition[k].x);
							one2oneDistMin = min(one2oneDistMin, one2oneDist);
						}
					}
					localSumMin += one2oneDistMin;
				}
			}
		globalSumMin = min(localSumMin, globalSumMin);
	} while (next_permutation(selectedStore.begin(), selectedStore.end()));

	cout << globalSumMin;
}