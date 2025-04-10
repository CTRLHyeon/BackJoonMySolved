#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <limits.h>
using namespace std;
//#define TEST
vector<pair<int, int>> parent(10001);
//first : 부모, second: price

int find(int x) {
	if (parent[x].first == x) return x;
	return parent[x].first = find(parent[x].first);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y].first = x;
	parent[x].second = min(parent[x].second, parent[y].second);
}
vector<int> cnt(10001, 0);

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, money;
	cin >> n >> m >> money;
	for (int i = 1; i <= n; i++) {
		parent[i].first = i;
		cin >> parent[i].second;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	int result = 0;
	
	for (int i = 1; i <= n; i++) {
		if (cnt[find(i)] == 0) {
			cnt[find(i)] = 1;
			money -= parent[find(i)].second;
			result += parent[find(i)].second;
		}
		if (money < 0) {
			cout << "Oh no";
			return 0;
		}
	}
	cout << result;

#ifdef TEST

	for (int i = 1; i <= n; i++) {
		cout << "<" << parent[i].first << ' ' << parent[i].second << "> ";
	}
	cout << '\n';
#endif

}