#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#define 십억 1000000000
using namespace std;

vector<vector<int>> dist(401, vector<int>(401, 십억));

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 십억;
	for (int i = 1; i <= n; i++) {
			ans = min(ans, dist[i][i]);
	}
	(ans < 십억) ? cout << ans : cout << "-1";
}