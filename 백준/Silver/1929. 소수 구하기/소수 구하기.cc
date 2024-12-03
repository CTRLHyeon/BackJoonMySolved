#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;
void prime(int num);
vector<int>che(1000001, 1);
int main() {
	che[0] = 0;
	che[1] = 0;
	for (int i = 2; i <= 1000; i++) {
		if (che[i])
			prime(i);
	}

	

	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (che[i])
			cout << i << '\n';
	}
}

void prime(int num) {
	for (int i = 2; i <= 500000;i++) {
		if (num * i > 1000000)
			break;
		else {
			che[num * i] = 0;
		}
	}
}