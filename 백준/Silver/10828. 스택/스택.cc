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

long long dp[1001] = { 0 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    stack<int>stk;
    int n;
    cin >> n;
    while(n--){
        string word;
        cin >> word;
        if (word == "push"){
            int x;
            cin >> x;
            stk.push(x);
        }
        else if (word == "pop"){
            if (stk.empty())
            cout << "-1\n";
            else {
            cout << stk.top()<<"\n";
            stk.pop();
            }
        }
        else if (word == "size")
        cout << stk.size()<<"\n";
        else if (word == "empty")
            cout << stk.empty()<<"\n";
            else {
                if(stk.empty())
                cout <<"-1\n";
                else cout << stk.top()<<"\n";
            }
    }
}