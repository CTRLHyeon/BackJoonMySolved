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
    long long k, n, result=0;
    cin >> k >> n;
    vector<long long>lan(k);
    long long maxlen = 0;
    for (int i = 0; i < k; i++) {
        cin >> lan[i];
        if (lan[i] > maxlen) maxlen = lan[i];
    }

    long long left = 1, right = maxlen, mid;   //mid 는 길이

    while (left <= right) {
        long long target = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < k; i++) {
            target += lan[i] / mid;
        }
        if (target >= n) {
            left = mid + 1;
            if (mid > result)
                result = mid;
        }

        else {
            right = mid - 1;
        }

        //printf("current mid: %d, traget: %d\n", mid, target);
    }
    cout << result;

}