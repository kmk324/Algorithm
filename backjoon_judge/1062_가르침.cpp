#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//K개의 글자를 가르쳐서
//N개의 단어를 최대한 가르쳐야함.
//antic. 최소 5개는 알아야 1이상 가르침.
//21c10 == 약350000 -> nextPermu가능.
vector<string> word;
bool isTeached[123]; //a ~ z 97 ~122
bool forNextPer[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int wordSize, possibleTeachAl;
	string temp, forPushWord;
	cin >> wordSize >> possibleTeachAl;

	possibleTeachAl -= 5;
	for (int i = 0; i < wordSize; i++)
	{
		cin >> temp;
		forPushWord = "";
		if (temp.size() == 8)
			word.push_back(temp);
		else {
			for (int i = 4; i < temp.size() - 4; i++)
				forPushWord += temp[i];
			word.push_back(forPushWord);
		}
	}

	if (possibleTeachAl < 0)
	{
		cout << 0;
		return 0;
	}

	//brute force
	int answer = 0;
	int loopMax = 0;
	for (int i = 0; i < possibleTeachAl; i++)
	{
		forNextPer[20-i] = 1;
	}

	sort(forNextPer, forNextPer+21);
	do {
		loopMax = 0;
		//select teachAlpha
		memset(isTeached, 0, sizeof(isTeached));
		isTeached[int('a')] = true;
		isTeached[int('n')] = true;
		isTeached[int('t')] = true;
		isTeached[int('i')] = true;
		isTeached[int('c')] = true;
		char remainAlpha[21] = { 'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l',
		'm', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z' };
		for (int i = 0; i < 21; i++)
		{
			if (forNextPer[i])
				isTeached[(remainAlpha[i])] = true;
		}

		for (int i = 0; i < word.size(); i++)
		{
			if (loopMax + word.size()-1 - i < answer)
				break;
			for (int j = 0; j < word[i].size(); j++)
			{
				if (!isTeached[word[i][j]])
					break;
				else if (j == word[i].size()-1)
					loopMax++;
			}
		}
		answer = max(answer, loopMax);
	} while (next_permutation(forNextPer,forNextPer+21));
	
	cout << answer;
}