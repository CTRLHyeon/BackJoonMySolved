#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;

int erased = 0;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int command;
		cin >> command;
		if (command) {
			heap.push(command);
		}
		else {
			if (heap.size() == 0) {
				cout << "0\n";
			}
			else {
				cout << heap.top() << '\n';
				heap.pop();
			}
		}
	}
}