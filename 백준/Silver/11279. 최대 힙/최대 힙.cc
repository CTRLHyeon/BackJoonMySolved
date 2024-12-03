#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;

priority_queue<int, vector<int>, less<int>> heap;

int erased = 0;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int size = 0;
	int T;
	cin >> T;
	while (T--) {
		int command;
		cin >> command;
		if (command) {		//0이 아니면
			heap.push(command);
			size++;
		}
		else {				//0이면
			if (size == 0) {
				cout << "0\n";
			}
			else {
				cout << heap.top() << '\n';
				heap.pop();
				size--;
			}
		}
	}
}