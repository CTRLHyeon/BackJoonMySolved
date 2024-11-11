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

    int cnt = 0;
    int n;
    cin >> n;
    for (int i = 6; i >= 0; i--) {
        if (n >= (int) pow(2, i)) {
            n -= (int) pow(2, i);
            cnt++;
        }
    }
    cout << cnt;
}