#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


int MIN(int a, int b) {
    return (a > b) ? b : a;
}
//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// 오름차순 : <
// 내림차순 : >
bool cmp(int a, int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int a, b, cnt = 0;
    cin >> a >> b;
    vector<int> v(1, 0);
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            cnt++;
            v.push_back(i);
        }
    }
    if (b <= cnt) {
        cout << v[b];
    }
    else {
        cout << 0;
    }
}