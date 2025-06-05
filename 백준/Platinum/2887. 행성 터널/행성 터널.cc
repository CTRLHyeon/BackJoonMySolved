#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> emi(100001);



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
struct coord {
	int num;
	int x;
	int y;
	int z;
};

bool xcmp(coord a, coord b) { return a.x < b.x; }
bool ycmp(coord a, coord b) { return a.y < b.y; }
bool zcmp(coord a, coord b) { return a.z < b.z; }
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) emi[i] = i;
	priority_queue<edge, vector<edge>, cmp> pq;
	vector<coord> hello(n);
	for (int i = 0; i < n; i++) {
		hello[i].num = i + 1;
		cin >> hello[i].x >> hello[i].y >> hello[i].z;
	}

	sort(hello.begin(), hello.end(), xcmp);
	for (int i = 0; i < n-1; i++) {
		pq.push({ hello[i].num, hello[i + 1].num, abs(hello[i].x - hello[i + 1].x) });
	}
	sort(hello.begin(), hello.end(), ycmp);
	for (int i = 0; i < n - 1; i++) {
		pq.push({ hello[i].num, hello[i + 1].num, abs(hello[i].y - hello[i + 1].y) });
	}
	sort(hello.begin(), hello.end(), zcmp);
	for (int i = 0; i < n - 1; i++) {
		pq.push({ hello[i].num, hello[i + 1].num, abs(hello[i].z - hello[i + 1].z) });
	}

	int ans = 0;

	while (!pq.empty()) {
		edge temp = pq.top();
		//cout << "탑: " << temp.s << ' ' << temp.e << ' ' << temp.cost << '\n';
		pq.pop();
		if (find(temp.s) == find(temp.e)) continue;
		Union(temp.s, temp.e);
		ans += temp.cost;
	}
	cout << ans;
}