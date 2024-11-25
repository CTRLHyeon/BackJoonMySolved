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

int MAX(int a, int b) { return (a < b) ? b : a; };

struct s {
	string name;
	long long hash = 0;
};
bool cmp(string a, string b) {
	for (int i = 0; i < MAX(a.size(), b.size()); i++) {
		if (a[i] != b[i])
			return a < b;
		else
			continue;
	}
	return a < b;	//default;
};
bool intcmp(long long a, long long b) {
	return a < b;
};

bool structcmp(s a, s b) {
	return a.hash < b.hash;
}


int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;

	vector<string> n(a);
	vector<string> result;

	for (int i = 0; i < a; i++) {
		cin >> n[i];
	}

	sort(n.begin(), n.end(), cmp);		//문자열 정렬

	
	for (int i = 0; i < b; i++) {			//보도 못한거 입력
		string temp;
		cin >> temp;
		if (binary_search(n.begin(), n.end(), temp))
			result.push_back(temp);
	}

	sort(result.begin(), result.end(), cmp);

	cout << result.size();
	for (int i = 0; i < result.size(); i++) {
		cout << '\n' << result[i];
	}
}