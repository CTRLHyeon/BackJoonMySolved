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
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long cnt = 0;
	int i=0;
	while (cnt <= n) {
		i++;
		cnt += i;
	}
	cout << i - 1;
}