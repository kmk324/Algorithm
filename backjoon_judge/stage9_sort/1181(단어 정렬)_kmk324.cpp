//�ܾ� ���� ����.
//1. ���̼������ ����.
//2. ���� �����̸� ���ĺ������� ����.
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

	//�Ʒ��� �� ���.
	for (int i = 0; i < WordSize; i++)
	{
		if (i == 0)
		{
			cout << word[i] << endl;
		}
		else if (word[i] != word[i - 1]) //i==0�̸� �ڿ� || ������ ����x
		{
			cout << word[i] << endl;
		}
	}

	return 0;
}