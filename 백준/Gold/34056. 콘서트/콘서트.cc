#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n;
	vector<long long> HP(n + 1, 0);
	for (int i = 0; i < n; i++) cin >> HP[i + 1];
	cin >> q;
	for (int i = 0; i < q; i++) {
		int cmd, c, x;
		cin >> cmd;

		if (cmd - 1) {
			cin >> c;
			cout << HP[c] << '\n';
		}
		else {
			cin >> c >> x;
			int lx = x, rx = x;
			int lc = c, rc = c + 1;
			while (lx > 0 && lc >= 1) {
				if (HP[lc] >= lx) {
					HP[lc] += lx;
					lx = 0;
				}
				else {
					lx -= HP[lc];
					HP[lc--] *= 2;
				}
			}
			while (rx > 0 && rc <= n) {
				if (HP[rc] >= rx) {
					HP[rc] += rx;
					rx = 0;
				}
				else {
					rx -= HP[rc];
					HP[rc++] *= 2;
				}
			}
		}
	}
}