#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;
void init(int num);
vector<int> v(100001, 1000);
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i * i <= n; i++) {	//제곱수는 1
		v[i * i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		init(i);
	}
	cout << v[n];
}
void init(int num) {
	for (int i = 1; i * i < num; i++) {
		
		v[num] = MIN(v[num], v[num - i * i] + 1);
	}
}
