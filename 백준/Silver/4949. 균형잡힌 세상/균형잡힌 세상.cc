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
	char s[101];
	cin.getline(s, 101);

	while (strcmp(s, ".") != 0) {
		int len = strlen(s);
		int result = 1;
		stack<int> stk;
		for (int i = 0; i < len; i++) {
			if (s[i] == '(')
				stk.push(s[i]);
			else if (s[i] == ')') {
				if (stk.empty()) {
					result = 0;
				}
				else if (stk.top() == '[') {
					result = 0;
				}
				if (stk.size() != 0)
					stk.pop();
			}
			else if (s[i] == '[')
				stk.push(s[i]);
			else if (s[i] == ']') {
				if (stk.empty()) {
					result = 0;
				}
				else if (stk.top() == '(') {
					result = 0;
				}
				if (stk.size() != 0)
					stk.pop();
			}
		}
		if (stk.size() != 0)
			result = 0;
		result ? cout << "yes\n" : cout << "no\n";
		cin.getline(s, 101);
	}
}
