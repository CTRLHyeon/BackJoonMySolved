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


vector<int> parent(1000001);
vector<int> cnt(1000001, 1);
int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
    cnt[x] += cnt[y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i <= 1000000; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'I') {
            int a, b;
            cin >> a >> b;
            if (find(a) != find(b)) Union(a, b);
        }
        else {
            int a;
            cin >> a;
            cout << cnt[find(a)] << '\n';
        }
#ifdef  TEST
        cout << "parent: ";
        for (int i = 1; i <= 5; i++) {
            cout << parent[i] << ' ';
        }
        cout << "\ncnt: ";
        for (int i = 1; i <= 5; i++) {
            cout << cnt[i] << ' ';
        }
        cout << "\n\n";
#endif TEST
    }
}