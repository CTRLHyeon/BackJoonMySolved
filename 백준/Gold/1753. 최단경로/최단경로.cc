#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int n, m, start, a, b, w;

//간선 정보를 저장할 구조체
struct edge {
	int v;	//대상 정점 번호
	int w;	//가중치
};
struct cmp {
	bool operator()(edge a, edge b) {
		return a.w > b.w;
	}
};
priority_queue < edge, vector<edge>, cmp>pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> start;
	vector<edge>graph[n+1];
	vector<bool> vis(n + 1, 0);
	vector<int>dist(n + 1, INT_MAX);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		graph[a].push_back({ b,w });
	}
	dist[start] = 0;
	pq.push({ start,0 });
	
	while (!pq.empty()) {
		int now = pq.top().v;
		pq.pop();
		if (vis[now]) continue;
		vis[now] = true;
		for (auto i : graph[now]) {
			int next = i.v;
			int weight = i.w;
			if (dist[next] > dist[now] + weight)
				dist[next] = dist[now] + weight;
			pq.push({ next, dist[next] });
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INT_MAX) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}