//1427 ��Ʈ �λ��̵�.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//sort �迭�� ������ sort(arr, arr+arr.length);
//������������ ���� sort(numStr.rbegin(), numStr.rend());
int main()
{
	string forSort;
	cin >> forSort;	
	sort(forSort.rbegin(), forSort.rend());
	cout << forSort << endl;
	return 0;
}