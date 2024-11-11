#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// 오름차순 : <
// 내림차순 : >
bool cmp(string a, string b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    vector <int> dp(200);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];  //dp초기화
        //printf("i = %d, dp[%d]: %d\n", i, i, dp[i]);
    }


    int n;
    while (T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
        
}