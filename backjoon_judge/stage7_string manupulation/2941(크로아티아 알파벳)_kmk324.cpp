//Croatian Alphabet
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Question;
	int CroatianAlphaCount = 0;
	cin >> Question;

	for (int i = 0; i < Question.length(); i++)
	{
		if (Question[i] == 'c' && Question[i+1] == '=')
		{
			CroatianAlphaCount++;
			i++;
		}
		else if (Question[i] == 'c' && Question[i + 1] == '-')
		{
			CroatianAlphaCount++;
			i++;
		}
		else if (Question[i] == 'd' && Question[i + 1] == '-')
		{
			CroatianAlphaCount++;
			i++;
		}
		else if (Question[i] == 'l' && Question[i + 1] == 'j')
		{
			CroatianAlphaCount++;
			i++;
		}
		else if (Question[i] == 'n' && Question[i + 1] == 'j')
		{
			CroatianAlphaCount++;
			i++;
		}
		else if (Question[i] == 's' && Question[i + 1] == '=')
		{
			CroatianAlphaCount++;
			i++;
		}
		else if (Question[i] == 'z' && Question[i + 1] == '=')
		{
			CroatianAlphaCount++;
			i++;
		}
		else if (Question[i] == 'd' && Question[i + 1] == 'z' && Question[i + 2] =='=' )
		{
			CroatianAlphaCount++;
			i=i+2;
		}
		else
		{
			CroatianAlphaCount++;
		}
	}
	cout << CroatianAlphaCount;
}