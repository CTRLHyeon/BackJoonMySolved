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
bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    else return a.size() < b.size();
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string>str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];

    sort(str.begin(), str.end(), cmp);

    for (int i = 0; i < n; i++) {
        if (i > 0 && str[i] == str[i - 1])
            continue;
        cout << str[i] << '\n';
    }
    
}