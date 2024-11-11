#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


int MIN(int a, int b) {
    return (a > b) ? b : a;
}
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

    int n, m;       //n은 세로, m은 가로
    cin >> n >> m;
    vector <string> chess(n), black, white;
    for (int i = 0; i < n; i++)
        cin >> chess[i];     //체스판 입력
    black = { "BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" };
    white = { "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW" };
    
    int result = INT_MAX;
    for (int i = 0; i <= n - 8; i++) {
        for (int ii = 0; ii <= m - 8; ii++) {
            ///
            int blackcnt = 0, whitecnt = 0;
            for (int iii = 0; iii < 8; iii++) {
                for (int iv = 0; iv < 8; iv++) {            ///4중 반복문 레전드..
                    if (chess[iii + i][iv + ii] == black[iii][iv])
                        blackcnt++;     //맞는 갯수
                    if (chess[iii + i][iv + ii] == white[iii][iv])
                        whitecnt++;     //맞는 갯수
                    result = MIN(result, MIN(64-blackcnt, 64-whitecnt));
                }
            }
        }
    }
    cout << result;
}
