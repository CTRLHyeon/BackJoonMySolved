#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;

struct edge{
	int dest;
	int cost;
};

struct cmp{
	bool operator()(edge a, edge b){
		return a.cost > b.cost;
	}
};

bool key(int a, int b){
	return a > b;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	while (T--){
		int n, d, start, cnt = 1;
		cin >> n >> d >> start;

		vector<int> distance (n+1, INT_MAX);
		vector<int> visited(n+1, 0);
		vector<int> infected(n+1,0);
		vector<vector<edge>> graph(n+1);
		priority_queue<edge, vector<edge>, cmp> pq;

		for (int i=0; i<d; i++){
			int a,b,c;
			cin >> a >> b >> c;
			graph[b].push_back({a,c});
		}

		distance[start] = 0;
		infected[start] = 1;
		pq.push({start,0});
		int last = 0;

		while (!pq.empty()){
			int now = pq.top().dest;
			pq.pop();
			if(visited[now]) continue;
			visited[now]=1;
			for (auto i : graph[now]){
				if (distance[i.dest] > distance[now] + i.cost){
					distance[i.dest] = distance[now]+i.cost;
					pq.push({i.dest, distance[i.dest]});
					if (!infected[i.dest]){
						cnt++;
						infected[i.dest] = 1;
					}
				}
			}
			
		}
		for (int i=0; i<=n; i++){
			if (distance[i] > last && distance[i] != INT_MAX)
				last = distance[i];
		}
		cout << cnt << ' ' << last<< '\n';
	}
}