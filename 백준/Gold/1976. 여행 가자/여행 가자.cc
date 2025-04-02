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

vector<int> parent(201);
vector<vector<int>> map(201, vector<int>(201, 0));

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
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) Union(i, j);
		}
	}
	for (int i = 1;i <= n; i++) {
		parent[i] = find(parent[i]);
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << parent[i] << ' ';
	//}

	queue <int> q;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}

	int result = parent[q.front()];
	for (int i = 0; i < m; i++) {
			if (result != parent[q.front()]) {
				cout << "NO";
				return 0;
		}
		q.pop();
	}
	cout << "YES";
}