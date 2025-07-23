#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				//cout << a[i] << ' ' << b[j] << ", " << i << ' ' << j << '\n';
			}
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	//for (int i = 1; i <= a.size(); i++) {
	//	for (int j = 1; j <= b.size(); j++) cout << dp[i][j] << ' ';
	//	cout << '\n';
	//}
	int result = 0;
	for (int i = 0; i <= a.size(); i++)
		result = max(result, dp[i][b.size()]);
	cout << result;
}