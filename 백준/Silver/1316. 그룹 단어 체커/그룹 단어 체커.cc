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
    for (int i = 0; i < n; i++) {
        int isgroup = 1;        //그룹단어일지 조사하기 위한 변수. 그룹단어가 아닐 시 0
        int cnt[26] = { 0 };    //카운팅정렬 초기화
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); i++) {
            if (cnt[str[i] - 'a'] == 0) {
                cnt[str[i] - 'a'] = 1;
            }
            else if (cnt[str[i] - 'a'] == 1 && str[i] != str[i - 1]) {
                isgroup = 0;
                break;
            }   //그룹단어가 아닐 조건: 이미 str[i]가 등장함 && 뒷문자가 str[i]가 아님

        }
        if (isgroup)
            result++;
    }
    cout << result;
}