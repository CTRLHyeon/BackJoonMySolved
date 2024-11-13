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
int main() {
	int n;
	cin >> n;

	vector <int> dp(5001, -1);

	for (int i = 0; i <= 4; i++) {
		int temp = 3*i;		//i = 3 : 9, 14, 19, 24 ...
		while (temp <= n) {
			dp[temp] = i + (temp - 3 * i) / 5;	//24 = 3 +  (24-9)/5
			temp += 5;
		}
	}
	cout << dp[n];
}