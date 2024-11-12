#define _CRT_SECURE_NO_WARNINNGS
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

int MIN(int a, int b) { return (a > b) ? b : a; }

//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// 오름차순 : <
// 내림차순 : >
bool cmp(int a, int b) {return a < b;}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnta[10] = { 0 }, cntb[10] = { 0 };
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {     //사이즈가 다르면 (b가 더 크면) 무조건 0
        cout << '0';
        return 0;
    }
    int result = 0;
    int iseight = 0;        //8인가?
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '8' && b[i] == '8') {
            result++;
        }
        else if (a[i] != b[i]) break;
    }
    cout << result;
}