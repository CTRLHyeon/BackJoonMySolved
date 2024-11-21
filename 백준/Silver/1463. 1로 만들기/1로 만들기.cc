#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int MIN(int a, int b) { return (a > b) ? b : a; }

int main() {
	int n;
	cin >> n;

	vector <int> dp(n+1, INT_MAX);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
    
	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0 && i % 2 == 0)				//3의 배수 && 2의 배수
			dp[i] = MIN(dp[i / 3] + 1, MIN(dp[i / 2] + 1, dp[i - 1] + 1));
		else if (i % 3 == 0)						//3의 배수
			dp[i] = MIN(dp[i / 3] + 1, dp[i - 1] + 1);
		else if (i % 2 == 0)				
			dp[i] = MIN(dp[i / 2] + 1, dp[i - 1] + 1);
		else										//뭣도 아닐 때
			dp[i] = dp[i - 1] + 1;
	}
    
	cout << dp[n];
}