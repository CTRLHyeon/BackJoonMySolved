#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int maximum = 100 * n;
	vector<int> dp(maximum + 1,0);
	vector<int> app(n, 0);
	vector<int> val(n, 0);
	for (int i = 0; i < n; i++) cin >> app[i];
	for (int i = 0; i < n; i++) cin >> val[i];
	for (int i = 0; i < n; i++) {
		for (int j = maximum; j >= val[i]; j--) {
			dp[j] = max(dp[j], dp[j - val[i]] + app[i]);
		}
	}
	for (int i = 0;i <= maximum; i++) {
		if (!dp[i]) continue;
		if (dp[i] >= m) {
			cout << i;
			return 0;
		}
	}
}