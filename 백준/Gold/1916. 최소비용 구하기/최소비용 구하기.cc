#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int start, dest;
int n, m;		// 정점의 갯수, 간선의 갯수
//간선 정보를 저장할 구조체
struct edge {
	int v;	//대상 정점 번호
	long long w;	//가중치
};
struct cmp {
	bool operator()(edge a, edge b) {
		return a.w > b.w;
	}
};
priority_queue < edge, vector<edge>, cmp>pq;



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
	vector<edge> graph[n+1];
	vector<bool> visited(n+1,0);
	vector<long long> dist(n+1, 10000000000);

	for (int i=0; i<m; i++){
		int a,v;
		long long w;
		cin >>a>>v>>w;
		graph[a].push_back({v,w});
	}
	cin >> start >> dest;
	dist[start] = 0;
	pq.push({start,0});
	while (!pq.empty()){
		int now = pq.top().v;
		pq.pop();
		if (visited[now] == true) continue;
		visited[now] = true;

		for (auto i: graph[now]){
			//cout<<"씨발"<<pq.size()<<'\n';
			if (dist[i.v] > dist[now] + i.w){
				dist[i.v] = (long long)(dist[now] + i.w);
				pq.push({i.v, dist[i.v]});
			}
		}
	}
	cout << dist[dest];
}