#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int answer = -1;
int lastDay;
int bound = 0;
struct durationProfit {
	int duration, profit;
};

vector <durationProfit> allDurationProfit; //0,1,2,3,4,5,6 -> 1~7
										   //3,5,1,1,2,4,2
//1~7 -> 0~6이고 day개수가 7이므로 7까지 도착은 가능.
void dfs(int nowDay, int nowProfit, int bound) //bound,러프하게
{
	answer = max(answer, nowProfit);
	if (bound > answer && nowDay < lastDay)
	{
		if (nowDay + allDurationProfit[nowDay].duration <= lastDay)
		{
			dfs(nowDay + allDurationProfit[nowDay].duration, nowProfit + allDurationProfit[nowDay].profit, bound);
			dfs(nowDay + 1, nowProfit, bound - allDurationProfit[nowDay].profit);
		}
		else {
			dfs(nowDay + 1, nowProfit, bound - allDurationProfit[nowDay].profit);
		}
	}
}

int main()
{
	cin >> lastDay;

	int duration, profit;
	for (int i = 0; i < lastDay; i++) {
		cin >> duration >> profit;
		allDurationProfit.push_back({ duration,profit });
		bound += profit;
	}
	dfs(0, 0, bound);
	cout << answer;
}