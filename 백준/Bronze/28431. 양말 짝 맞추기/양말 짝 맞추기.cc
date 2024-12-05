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


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> cnt(10, 0);

	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		cnt[temp]++;
	}
	for (int i = 0; i < 10; i++) {
		if (cnt[i] % 2) {
			cout << i;
			return 0;
		}
	}
}