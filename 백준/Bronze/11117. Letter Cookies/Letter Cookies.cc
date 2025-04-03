#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, m;
	cin >> T;
	while(T--){vector<int>alpha(26, 0);
	string temp;
	cin >> temp;
	for (int j = 0; j < temp.size(); j++) {
		alpha[temp[j] - 'A']++;
	}


		cin >> m;
		for (int i = 0; i < m; i++) {

			vector<int> cmp(26, 0);
			string temp;
			cin >> temp;
			int result = 0;	//1이면 예스
			for (int i = 0; i < temp.size(); i++) {
				cmp[temp[i] - 'A']++;
			}
			for (int i = 0; i < 26; i++) {
				if (cmp[i] > alpha[i]) {
					result = 1;
				}

			}
			if (!result) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}