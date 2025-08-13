#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
vector<int> parent(1001);
vector<int> hello(1001);
int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	int x = find(a);
	int y = find(b);
	parent[y] = x;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;

	while (m--) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++) hello[find(i)] = 1;
	int result = 0;
	for (int i = 1; i <= n; i++)result += hello[i];
	cout << result;
}