#include <iostream>
#include <string>

using namespace std;
int main()
{
	int wordCount = 0;
	string Question="";
	getline(cin,Question);
	for (int i = 0; i < Question.length(); i++)
	{
		if (Question[i] == ' ' && Question[i+1] != ' ' )
		{
			wordCount++;
		}
		if (i==Question.length() - 1 && Question[i] == ' ')
		{
			wordCount--;
		}
	}
	if (Question[0] != ' ')
	{
		wordCount++;
	}
	cout << wordCount;
}