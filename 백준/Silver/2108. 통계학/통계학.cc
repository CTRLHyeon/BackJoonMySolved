#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> cnt(8001);
	double sum = 0;	//평균 구할거임
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		cnt[v[i] + 4000]++;
		sum += v[i];
	}
	sum /= n;
	sort(v.begin(), v.end());
	int most, mostcnt = 0;	//최빈수와 최빈수의 수
	int issecond=0;	//최빈수를 두번째로 작은 값으로 정하기 위해
	for (int i = 0; i <= 8000; i++) {
		if (cnt[i] > mostcnt) {
			most = i - 4000;
			mostcnt = cnt[i];
			issecond = 0;
		}
		else if (cnt[i] == mostcnt && issecond == 0) {
			most = i - 4000;
			issecond = 1;
		}
	}
	if (sum < 0) cout << (int)(sum - 0.5) << '\n';
	else cout << (int)(sum + 0.5) << '\n';
	cout << v[n / 2] << '\n';
	cout << most << '\n';
	cout << v[n - 1] - v[0];
}
