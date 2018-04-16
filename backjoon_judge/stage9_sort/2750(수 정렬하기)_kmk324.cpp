#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> Question;
	int N,QuestionNum;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> QuestionNum;
		Question.push_back(QuestionNum);
	}
	sort(Question.begin(),Question.end());
	for (int i = 0; i < N; i++)
	{
		cout << Question[i] << endl;
	}
	return 0;
}