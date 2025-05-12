#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return (a + b) > (b + a);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, iszero = 1;
	cin >> n;
	vector<string> s(n);
	int maxSize = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i] != "0") iszero = 0;
		maxSize = max(maxSize, (int)s[i].size());
	}
	if (iszero) {
		cout << 0;
		return 0;
	}
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
}