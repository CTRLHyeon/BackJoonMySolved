#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

struct edge {
	int cost;
	int dest;
};

struct cmp {
	bool operator()(edge a, edge b) {
		return a.cost > b.cost;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	priority_queue <edge, vector<edge>, cmp> pq;
	vector<int> visited(n + 1);
	vector<edge> graph[n + 1];
	vector<int> cost(n+1, INT_MAX);
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	int start = 1;
	cost[start] = 0;
	pq.push({0,start});
	while(!pq.empty()){
		int now = pq.top().dest;
		pq.pop();
		if (visited[now]) continue;
		
		visited[now] = 1;
		
		for (auto i: graph[now]){
			if (cost[i.dest] > cost[now] + i.cost){
				cost[i.dest] = cost[now]+i.cost;
				pq.push({cost[i.dest],i.dest});
			}
		}
	}
	int pass = 0;
	int v1, v2;
	cin >> v1 >> v2;

	int start_to_v1, start_to_v2, start_to_n;
	start_to_v1 = cost[v1];
	start_to_v2 = cost[v2];
	start_to_n = cost[n];
	//예외 1: 1->v1, 1->v2, 1->n 이 없음
	if (start_to_v1 == INT_MAX || start_to_v2 == INT_MAX || start_to_n == INT_MAX)
		pass = -1;

	start = v1;
	for (int i=0; i<=n; i++){
		visited[i] = 0;
	}
	for (int i=0; i<=n; i++){
			cost[i]= INT_MAX;
	}
	cost[v1] = 0;
	pq.push({cost[v1],start});
	while(!pq.empty()){
		int now = pq.top().dest;
		pq.pop();
		if (visited[now]) continue;
		
		visited[now] = 1;
		
		for (auto i: graph[now]){
			if (cost[i.dest] > cost[now] + i.cost){
				cost[i.dest] = cost[now]+i.cost;
				pq.push({cost[i.dest],i.dest});
			}
		}
	}
	int v1_to_n, v1_to_v2;
	v1_to_n = cost[n];
	v1_to_v2 = cost[v2];
	//예외 2:  v1->n, v1->v2가 없음
	if (v1_to_n == INT_MAX || v1_to_v2 == INT_MAX)
		pass = -1;

	for (int i=0; i<=n; i++){
		visited[i] = 0;
	}
	for (int i=0; i<=n; i++){
			cost[i]= INT_MAX;
	}
	start = v2;
	cost[v2] = 0;
	pq.push({cost[v2],start});
	while(!pq.empty()){
		int now = pq.top().dest;
		pq.pop();
		if (visited[now]) continue;
		
		visited[now] = 1;
		
		for (auto i: graph[now]){
			if (cost[i.dest] > cost[now] + i.cost){
				cost[i.dest] = cost[now]+i.cost;
				pq.push({cost[i.dest],i.dest});
			}
		}
	}
	int v2_to_n, v2_to_v1;
	v2_to_n = cost[n];
	v2_to_v1 = cost[v1];
	//예외 3: v2->n가 없음
	if (v2_to_n == INT_MAX)
	    pass = -1;
	
	if (pass) cout << -1;
	else cout << min((start_to_v1 + v1_to_v2 + v2_to_n), (start_to_v2 + v2_to_v1 + v1_to_n));
}