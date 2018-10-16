#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compFunc(int a, int b)
{
	return a > b;
}

int main()
{
	vector<int>numA;
	vector<int>numB;
	int answer = 0;
	int numSize, forPush;
	cin >> numSize;
	for(int i=0; i<2; i++)
		for (int j = 0; j < numSize; j++)
		{
			cin >> forPush;
			if(i==0)
				numA.push_back(forPush);
			else
				numB.push_back(forPush);
		}

	sort(numA.begin(), numA.end());
	sort(numB.begin(), numB.end(), compFunc);
	
	for (int i = 0; i < numSize; i++)
		answer += numA[i] * numB[i];
	cout << answer;
}
