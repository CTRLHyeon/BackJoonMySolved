#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;

//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// 오름차순 : <
// 내림차순 : >

bool cmp(int a, int b) { return a < b; };
int MIN(int a, int b) { return (a > b) ? b : a; }
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	int is1 = 0;
	int is0 = 0;
	int cnt1 = 0;
	int cnt0 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (is1 == 0 && is0 == 0) {
			if (s[i]=='1') {
				is1 = 1;
				cnt1++;
				//printf("cnt1++ed, i:%d\n", i);
			}
			else {
				is0 = 1;
				cnt0++;
				//printf("cnt0++ed, i:%d\n", i);
			}
		}
		else if (is1) {
			if (s[i] == '0') {
				is1 = 0;
				is0 = 1;
				cnt0++;
			}
		}
		else if (is0) {
			if (s[i] == '1') {
				is0 = 0;
				is1 = 1;
				cnt1++;
			}
		}
	}
	cout << MIN(cnt1,cnt0);
}