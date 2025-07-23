#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	vector<int> s(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> s[i];
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i] > s[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}