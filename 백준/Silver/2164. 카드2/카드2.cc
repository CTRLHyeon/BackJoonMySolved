#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

int upcmp(int* a, int* b);             //퀵소트 오름차
int downcmp(int* a, int* b);           //퀵소트 내림차
void inttojari(int num, int jarisu[]); //자릿수 배열에 저장하는거
typedef long long intt;                //롱롱 ->인뜨

//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<int>q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size()>1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------


int upcmp(int* a, int* b) { return (*a - *b); }
int downcmp(int* a, int* b) { return (*b - *a); }
void inttojari(int num, int jarisu[]) {
    int jari = 0;
    int temp = num;
    for (int i = 0; pow(10, i) <= num; i++)
        jari++;
    for (int i = jari; i > 0; i--) {
        jarisu[jari - i] = temp / (int)pow(10, i - 1);
        temp -= temp / (int)pow(10, i - 1) * (int)pow(10, i - 1);
    }
}