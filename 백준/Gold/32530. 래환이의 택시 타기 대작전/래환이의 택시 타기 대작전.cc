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
    int n;
    cin >> n;
    vector <int> time(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d:%d", &a, &b);
        time[i] = 60 * a + b;
    }
    sort(time.begin(), time.end(), cmp);

    int cnt = 0, key = 0;

    while (key < n) {
        int constant = key;
        while (key < constant+3 && key<n) {
            //printf("씨발");
            if (time[key] <= time[constant] + 10)
                key++;
            else break;
        }
        cnt++;
        //printf("와일한번끝남ㅋ\n");
    }
    cout << cnt;

}