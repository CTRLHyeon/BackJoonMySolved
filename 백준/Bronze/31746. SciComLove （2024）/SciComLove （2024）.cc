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
bool cmp(int a, int b) { return a > b; };
int MAX(int a, int b) { return (a < b) ? b : a; }



int main() {
	int n;
	cin >> n;
	(n % 2) ? cout << "evoLmoCicS" : cout << "SciComLove";
}