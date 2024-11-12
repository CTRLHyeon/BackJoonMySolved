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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a != b) {
        //printf("와일 실행~\n");
        if (b % 2 == 0 && b / 2 >= a) {
            b /= 2;
            cnt++;
        }
        else {
            b--;
            cnt++;
        }
    }
    cout << cnt;
}