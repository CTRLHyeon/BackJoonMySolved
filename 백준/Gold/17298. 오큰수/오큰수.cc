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
	vector<int> v(n), result(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	stack<int> stk;
	int max = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] >= max) {	//v[i]가 역대 가장 큰 수면(처음도 여기에 포함)
			max = v[i];
			stk = stack<int>();
			stk.push(v[i]);
			result[i] = -1;
		}
		else {
			//stack<int>temp;	//임시용
			while (stk.size()) {
				if (stk.top() > v[i]) {	//스택의 수 (왼쪽의 수)가 더 큼
					result[i] = stk.top();
					stk.push(v[i]);
					break;
				}
				else {	//왼쪽에 더 큰 수가 아님
					//temp.push(stk.top());	//임시스택에 넣어놓기
					stk.pop();
				}

			}
			if (stk.empty())
				result[i] = -1;
		}
	}
	//결과 출력
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
}