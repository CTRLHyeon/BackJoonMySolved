#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;

bool cmp(int a, int b) { return a > b; };

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a.begin(), a.end(), cmp);


	int result = 0;
	for (int i = 0; i < n; i++) {
		int min = 2147;
		int temp;
		for (int j = 0; j < n; j++) {
			if (b[j] < min) {
				min = b[j];
				temp = j;
			}
		}
		b[temp] = 2147;
		result += a[i] * min;
	}
	cout << result;
}