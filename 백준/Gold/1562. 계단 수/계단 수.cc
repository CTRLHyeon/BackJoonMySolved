#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#define 롱롱 long long
#define 십억 1000000000
롱롱 dp[101][10][1024];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) dp[1][i][1 << i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int k = 1; k < 1024; k++) {	//0 and 9
			dp[i][0][k | 1] = (dp[i][0][k | 1] + dp[i - 1][1][k]) % 십억;

			dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % 십억;
		}
		for (int j = 1; j <= 8; j++) {		// 1 ~ 8
			for (int k = 1; k < 1024; k++) dp[i][j][k | (1 << j)] = (dp[i][j][k|(1<<j)] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % 십억;
		}
	}

	int ans = 0;
	for (int j = 0; j <= 9; j++) {
		ans += dp[n][j][1023];
		ans %= 십억;
	}
	cout << ans;

}