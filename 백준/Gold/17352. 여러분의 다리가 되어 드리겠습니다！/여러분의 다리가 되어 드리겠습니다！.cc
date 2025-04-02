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

vector<int>parent(300001);

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int nn = n - 2;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (nn--) {
		int a, b;
		cin >> a >> b;
		Union(a, b);

		
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = find(parent[i]);
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << parent[i] << ' ';
	//}
	//cout << '\n';
	for (int i = 1; i < n; i++) {
		if (parent[i] != parent[i + 1]) {
			cout << i << ' ' << i + 1;
			return 0;
		}
	}
}