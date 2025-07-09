#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

vector<int> train(100001);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k;
	cin >> k;
	int size = 0;
	while (pow(2, size) < k) size++;

	int count = 0;

	while (!(k % 2)) {
		count++;
		k = k >> 1;
	}
	cout << (int)pow(2,size) << ' ' << size - count;
}