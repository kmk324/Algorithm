//´ÙÀÌ¾ó
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Question;
	cin >> Question;
	int answer = 0;
	int ForOrder;
	for (int i = 0; i< Question.length() ; i++)
	{
		if (Question[i] == 'S')
		{
			ForOrder = 7;
		}
		else if (Question[i] >= 'T' && Question[i] <= 'V')
		{
			ForOrder = 8;
		}
		else if (Question[i] >= 'W' && Question[i] <= 'Z')
		{
			ForOrder = 9;
		}
		else
		{
			ForOrder = int(Question[i] - 65) / 3 + 2;
		}
		answer += ForOrder+1; 
	}
	cout << answer;
}