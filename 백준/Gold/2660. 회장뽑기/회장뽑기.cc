#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#define 십억 1000000000
using namespace std;

vector<vector<int>> dist(51, vector<int>(51, 십억));
vector<int> score(51, 1);
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
priority_queue<int, vector<int>, cmp> pq;

int main() {
	int n;
	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	//갱신완료
	//웅?
	int president = 100;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] >= 1000000000) continue;
			score[i] = max(score[i], dist[i][j]);
			
		}
		if (president > score[i]) {
			president = score[i];
			pq = priority_queue<int, vector<int>, cmp>();
			pq.push(i);
		}
		else if (president == score[i])
			pq.push(i);
	}
	//score구함

	cout << president << ' ' << pq.size() << '\n';
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}

}