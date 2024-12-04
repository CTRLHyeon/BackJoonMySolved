#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;


struct cor {
	int num;
	int zip;
	int order;
};

bool cmp(cor a, cor b) {
	return a.num < b.num;
}
bool ordercmp(cor a, cor b) { return a.order < b.order; };
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<cor> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].num;
		v[i].order = i;
	}

	sort(v.begin(), v.end(), cmp);

	int st = 0;
	v[0].zip = 0;

	for (int i = 1; i < v.size(); i++) {
		if (v[i].num != v[i-1].num)
			st++;
		v[i].zip = st;
	}
	v[v.size() - 1].zip = st;
	sort(v.begin(), v.end(), ordercmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].zip << ' ';
	}
}