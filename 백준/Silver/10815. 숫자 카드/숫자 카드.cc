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
    return a < b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n;
    vector<int>card(n);
    for (int i = 0; i < n; i++)
        cin >> card[i];
    sort(card.begin(), card.end());

    cin >> m;
    vector<int>target(m);
    for (int i = 0; i < m; i++)
        cin >> target[i];
    for (int i = 0; i < m; i++) {
        int key = target[i];

        int left = 0, right = n-1, mid;
        int found = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (card[mid] == key) {
                found = 1;
                break;
            }
            else if (card[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }
        cout << found << ' ';
    }
}