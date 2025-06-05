#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> emi(10001);



int find(int x) {
	if (emi[x] == x) return x;
	return emi[x] = find(emi[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	emi[x] = y;
}
struct edge {
	int s;
	int e;
	int cost;
};

struct cmp {
	bool operator()(edge x, edge y) {
		return x.cost > y.cost;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) emi[i] = i;

	priority_queue<edge, vector<edge>, cmp> pq;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}
	int ans = 0;

	while (!pq.empty()) {
		edge temp = pq.top();
		pq.pop();
		if (find(temp.s) == find(temp.e)) continue;
		Union(temp.s, temp.e);
		ans += temp.cost;
	}
	cout << ans;
}