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
	stack<int>stk;
	vector<char>result;
	int maxi = 0;	//스택에 푸시/팝 한 수 중 최대
	int prev = 0;	//전에 입력받은 수
	while (n--) {
		int temp;
		cin >> temp;	//현재 입력받은수.
		if (maxi < temp) {
			//cout << "템프가 맥시보다 크다. temp: " << temp << ", maxi: " << maxi << ",size: " << stk.size() << '\n';
			for (int i = maxi; i < temp; i++) {
				stk.push(i+1);
				result.push_back('+');
			}
			result.push_back('-');
			stk.pop();	//원하던 숫자 스택에 넣고 빼주기
		}
		else {	//맥시가 더 클 경우: 
				//1. temp가 이전의 수보다 작으면, 현재의 수가 나올때까지 팝팝팝
				//2. temp가 이전의 수보다 크면 (ex 4,1,2) 이미 팝해버렸으니 NO출력
			//cout << "템프가 맥시보다 작다. temp: " << temp << ", maxi: " << maxi << ",size: " <<stk.size() << '\n';
			if (temp < prev) {
				if (stk.size() == 0) {
					cout << "NO";
					return 0;
				}
				int top = stk.top();
				if (top != temp) {
					while (top != temp) {
						if (stk.size() == 0) {
							cout << "NO";
							return 0;
						}
						stk.pop();
						result.push_back('-');
						top = stk.top();
					}
					stk.pop();
					result.push_back('-');
				}
				else {
					stk.pop();
					result.push_back('-');
				}
			}
			else {
				cout << "NO";
				return 0;	//NO 출력후 강제종료
			}
		}
		if (temp > maxi) maxi = temp;	//맥시 값 최댓값으로 갱신
		prev = temp;
		//cout << "한번 돌았고 나머지 사이즈: " << stk.size()<<"\n\n";
	}

	for (int i = 0; i < result.size();i++) {
		cout << result[i] << '\n';
	}
}
