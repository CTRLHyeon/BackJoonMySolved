#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int>> dist(101, vector<int>(101, 1000000000));

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] < 1000000000)
				cout << dist[i][j] << ' ';
			else cout << "0 ";
		}
		cout << '\n';
	}
}