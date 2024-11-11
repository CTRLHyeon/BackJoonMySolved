#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// 오름차순 : <
// 내림차순 : >
bool cmp(int a, int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, result = 0;
    cin >> n;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp) {
            stk.push(temp);
        }
        else
            stk.pop();
    }
    int size = stk.size();
    for (int i = 0; i < size; i++) {
        result += stk.top();
        stk.pop();
    }
    cout << result;
}