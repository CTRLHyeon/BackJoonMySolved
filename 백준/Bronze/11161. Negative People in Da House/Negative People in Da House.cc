#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <limits.h>
#define elif else if
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> m;
        int sum = 0;
        int result = 0;
        while (m--) {
            int a, b;
            cin >> a>> b;
            sum += a - b;
            //cout << "sum: "<<sum << '\n';
            if (sum < 0) result = min(result, sum);
        }
        cout << -result << '\n';
    }
}