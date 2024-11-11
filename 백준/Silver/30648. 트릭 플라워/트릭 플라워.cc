#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

int upcmp(int* a, int* b) { return (*a - *b); }     //퀵소트 오름차
int downcmp(int* a, int* b) { return (*b - *a); }   //퀵소트 내림차


int printcount(int arr[], int n) {
    cout << "count: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] <<" ";
    cout << '\n';
    return 0;
}
//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

int map[1001][1001] = { 0 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, r;
    cin >> a >> b >> r;
    map[a][b]++;

    int repeat=1;
    while (repeat) {
        if (a + 1 + b + 1 < r) {
            a++;
            b++;
        }
        else {
            a /= 2;
            b /= 2;
        }
        map[a][b]++;
        if (map[a][b] - 1) {
            cout << repeat;
            return 0;
        }
        repeat++;
    }
}