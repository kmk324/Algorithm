#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//비밀번호 길이 8<=passwordLen. <=28
//각 숫자는 0~F (0~15)

//16진수 10진수화 할 수 있는 generic함수 구현.
//만들수 있는 비밀번호의 각 자리수는 passwordLen/4.

int answer16to10(string answer16) 
{
	int answer10 = 0;
	for (int i = 0; i < answer16.size(); i++)
	{
		if (answer16[i] >= 'A') //A=65
		{
			answer10 = answer10 + (answer16[i]-55) * int(pow(16, answer16.size() - i - 1));
		}
		else {
			answer10 = answer10 + (answer16[i]-48) * int(pow(16, answer16.size() - i - 1));
		}
	}
	return answer10;
}

string makePasswdFragment(string passwd, int passwdLen, int index)
{
	string passwdFragment ="";
	for (int i = 0; i < passwdLen; i++)
	{
		passwdFragment += passwd[index + i];
	}
	return passwdFragment;
}

int main(int argc, char** argv)
{
	int TcSize;
	int passwdSize;
	int largeSequence;
	string passwd;
	cin >> TcSize;
	vector<string> passwdGroup;
	string passwdFragment;
	string answer16;
	int answer;

	for (int test_case = 1; test_case <= TcSize; ++test_case)
	{
		passwdGroup.clear();
		cin >> passwdSize >> largeSequence >>passwd;
		//비밀번호 passwordLen/4단위로 잘라서 push.
		int eachPasswdLen = passwdSize / 4;
		for (int i = 0; i < passwd.size(); i++)
		{
			for (int j = 0; j <= passwd.size() - eachPasswdLen; j += eachPasswdLen)
			{
				passwdFragment = makePasswdFragment(passwd, eachPasswdLen, j);
				if (find(passwdGroup.begin(), passwdGroup.end(), passwdFragment) == passwdGroup.end())
				{
					passwdGroup.push_back(passwdFragment);
				}
				if (j >= (passwd.size() - (2*eachPasswdLen)+1) && j<=passwd.size()-eachPasswdLen ) //generic하게.
				{
					//한칸씩 passwd이동.
					int lastElement = passwd[passwd.size() - 1];
					for (int k = passwd.size()-1; k >0; k--)
					{
						passwd[k] = passwd[k - 1];
					}
					passwd[0] = lastElement;
				}
			}
		}
		sort(passwdGroup.rbegin(), passwdGroup.rend());
		answer16 = passwdGroup[largeSequence - 1];
		answer = answer16to10(answer16);
		cout << '#'<<test_case <<' '<< answer << endl;
	}
	return 0;
}
