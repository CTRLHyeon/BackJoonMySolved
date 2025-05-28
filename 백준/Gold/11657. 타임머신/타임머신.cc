#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct tq{
	int s;	//start
	int e;	//end
	int c;	//cost
};

vector<tq> edge(6000);
vector<long long> dist(501, INT_MAX);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	dist[1] = 0;
	for (int i = 0; i < m; i++){
		int a,b,c;
		cin >>a>>b>>c;
		edge[i] = {a,b,c};
	}
	
	for (int i = 0; i<n-1; i++){
		for (int j=0; j<m; j++){
			if (dist[edge[j].s] == INT_MAX) continue;

			if (dist[edge[j].e] > dist[edge[j].s] + edge[j].c)
				dist[edge[j].e] = dist[edge[j].s] + edge[j].c;
		}
	}
	for (int i=0; i<m; i++){
		if (dist[edge[i].s] == INT_MAX) continue;
		if (dist[edge[i].e] > dist[edge[i].s] + edge[i].c){
			cout << -1;
			return 0;
		}
	}
	for (int i=2; i<=n; i++)
		(dist[i] >= 100000000)? cout << -1<<'\n': cout << dist[i] << '\n';
}