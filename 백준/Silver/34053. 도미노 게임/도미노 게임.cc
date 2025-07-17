#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a < b; };
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	vector<int> linear;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			ans += temp;
			linear.push_back(temp);
		}

	sort(linear.begin(), linear.end(), cmp);
	ans -= linear[0];
	cout << ans;
}