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
void printq(queue<int>q);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    //printq(q);
    bool b = 1;
    while (q.size()!=1) {
    //    printq(q);

        if (b) {
            cout << q.front() << ' ';
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
        b = !b;
    }
    cout << q.front();
}

void printq(queue <int>q) {
    printf("queue: ");
    for (int i = 0; i < q.size(); i++) {
        cout << q.front() << ' ';
        q.pop();
    }
    printf("\n");
}