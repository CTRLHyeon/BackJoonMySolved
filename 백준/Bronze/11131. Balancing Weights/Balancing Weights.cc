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
        int cnt;
        cin >> cnt;
        int result = 0;
        for (int i = 0; i < cnt; i++) {
            int temp;
            cin >> temp;
            result += temp;
        }
        if (result < 0) cout << "Left\n";
        elif(result == 0) cout << "Equilibrium\n";
        else cout << "Right\n";
    }
}