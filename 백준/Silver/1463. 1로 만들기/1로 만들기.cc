#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;

//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// 오름차순 : <
// 내림차순 : >
bool cmp(int a, int b) { return a < b; };
int MIN(int a, int b) { return (a > b) ? b : a; }

void dpinit(int num, int max, int dp[]);

int dp[1000001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
	}

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	//dp[4] = 2;
	//dp[5] = 3;
	//dpinit(1, n, dp);

	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0 && i % 2 == 0)
			dp[i] = MIN(dp[i / 3] + 1, MIN(dp[i / 2] + 1, dp[i - 1] + 1));
		else if (i % 3 == 0)
			dp[i] = MIN(dp[i / 3] + 1, dp[i - 1] + 1);
		else if (i % 2 == 0)
			dp[i] = MIN(dp[i / 2] + 1, dp[i - 1] + 1);
		else
			dp[i] = dp[i - 1] + 1;
	}





	//for (int i = 1; i <= n; i++)
		//printf("%d: %d\n", i, dp[i]);
	cout << dp[n];

}

void dpinit(int num, int max, int dp[]) {
	if (num + 1 <= max)
		dp[num + 1] = MIN(dp[num + 1], dp[num] + 1);
	if (num * 2 <= max)
		dp[num * 2] = MIN(dp[num * 2], dp[num] + 1);
	if (num * 3 <= max)
		dp[num * 3] = MIN(dp[num * 3], dp[num] + 1);


	if (num + 1 <= max)
		dpinit(num + 1, max, dp);
	if (num * 2 <= max)
		dpinit(num * 2, max, dp);
	if (num * 3 <= max)
		dpinit(num * 3, max, dp);
}