//1427 소트 인사이드.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//sort 배열을 쓸때는 sort(arr, arr+arr.length);
//내림차순으로 정렬 sort(numStr.rbegin(), numStr.rend());
int main()
{
	string forSort;
	cin >> forSort;	
	sort(forSort.rbegin(), forSort.rend());
	cout << forSort << endl;
	return 0;
}