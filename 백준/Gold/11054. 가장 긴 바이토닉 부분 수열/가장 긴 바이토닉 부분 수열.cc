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
	vector<int> dp2(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i] > s[j]) dp[i] = max(dp[i], dp[j] + 1);
		}	
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= i; j--) {
			if (s[i] > s[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
		}	//1 5 2 1 4 3 4 5 2 1
			//1 5 2 1 4 3 3 3 2 1
	}
	//for (int i = 1; i <= n; i++) cout << dp2[i] << ' ';
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[i] + dp2[i]);
	}
	cout << result-1 ;
}