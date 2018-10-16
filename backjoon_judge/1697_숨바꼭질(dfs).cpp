#include<iostream>
#include <algorithm>
using namespace std;
int dfs(int n, int k) {
	if (n >= k) return n - k;
	if (k % 2 == 0) return min(k - n, dfs(n, k / 2) + 1);
	else return min(dfs(n, k + 1), dfs(n, k - 1)) + 1;
}
int main() {
	int n, k; cin >> n >> k;
	if (n == 0) cout << 1 + dfs(1, k);
	else cout << dfs(n, k);
}