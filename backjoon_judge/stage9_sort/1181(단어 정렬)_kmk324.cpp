//단어 정렬 문제.
//1. 길이순서대로 정렬.
//2. 같은 길이이면 알파벳순서로 정렬.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string tempForInsertion;
vector<string> word;

bool sortFunction(string& s1, string& s2) {
	int s1Size = s1.size();
	int s2Size = s2.size();

	if (s1Size == s2Size) {
		return s1 < s2;
	}

	return s1Size < s2Size;
}

int main()
{
	int WordSize;
	cin >> WordSize;
	for (int i = 1; i <= WordSize; i++)
	{
		cin >> tempForInsertion;
		word.push_back(tempForInsertion);
	}

	sort(word.begin(), word.end(), sortFunction);

	//아래는 답 출력.
	for (int i = 0; i < WordSize; i++)
	{
		if (i == 0)
		{
			cout << word[i] << endl;
		}
		else if (word[i] != word[i - 1]) //i==0이면 뒤에 || 조건은 수행x
		{
			cout << word[i] << endl;
		}
	}

	return 0;
}