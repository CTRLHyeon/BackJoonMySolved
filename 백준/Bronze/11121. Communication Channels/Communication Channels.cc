#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <limits.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        if (a == b) cout << "OK\n";
        else cout << "ERROR\n";
    }
}