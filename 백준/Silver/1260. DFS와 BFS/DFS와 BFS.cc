#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> map(1001, vector<int>(1001, 0));
vector<int> visited(1001, 0);
vector<int> result;
//1260 DFS와 BFS
vector<int> dp(1001);

void bfs(int, int, int);
void visit(int);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	visit(v);
	for (int i = 1; i <= n; i++) {
		if (map[v][i] && !visited[i]) {
			bfs(v, i, n);
		}
	}
	for (auto i : result) cout << i << ' ';
	cout << '\n';
	visited = vector<int>(1001, 0);
	result = vector<int>();
	queue<int> q;

	q.push(v);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (visited[temp]) continue;
		visit(temp);
		for (int i = 1; i <= n; i++) {
			if (map[temp][i] && !visited[i])
				q.push(i);
		}
	}
	for (auto i : result) cout << i << ' ';
}
void bfs(int a, int b, int n) {
	visit(b);
	for (int i = 1; i <= n; i++) {
		if (map[b][i] && !visited[i])
			bfs(b, i, n);
	}
}
void visit(int n) {
	visited[n] = 1;
	result.push_back(n);
}