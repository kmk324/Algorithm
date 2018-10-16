//nextpermu로 해보자
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lottoNum[50]; // 로또 숫자를 담음.
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int numSize=-1;
	int forInsert;
	vector<int> lotto; //로또의 선택 및 미선택 구분.
	while (numSize!=0)
	{
		lotto.clear();
		cin >> numSize;
		for (int i = 1; i <= numSize; i++)
		{
			cin >> forInsert;
			lottoNum[i] = forInsert;
			if (i <= 6)
				lotto.push_back(0);
			else
				lotto.push_back(1);
		}
		do {
			for (int i = 0; i < numSize; i++)
			{
				if (lotto[i] == 0)
					cout << lottoNum[i+1] << ' ';
			}
			cout << '\n';
		} while (next_permutation(lotto.begin(), lotto.end()));
		cout << '\n';
	}
}