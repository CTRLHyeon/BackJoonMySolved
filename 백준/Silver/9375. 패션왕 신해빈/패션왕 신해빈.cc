#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
////////////////////
//9375 패션왕 신해빈//
////////////////////

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		map <string, int> m;
		vector<int> cloth;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			m[b]++;
		}
		for (auto i : m) cloth.push_back(i.second);
		int result = 1;
		for (int i = 0;i < cloth.size(); i++) result *= (cloth[i] + 1);
		cout << result - 1 << '\n';
	}
}