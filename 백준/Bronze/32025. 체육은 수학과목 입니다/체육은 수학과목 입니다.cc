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

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> map(15, vector<int>(15, 0));
	int a, b;
	cin >> a >> b;
	cout << min(a, b) * 50;
}