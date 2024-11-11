#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int upcmp(int* a, int* b);             //퀵소트 오름차
int downcmp(int* a, int* b);           //퀵소트 내림차
void inttojari(int num, int jarisu[]); //자릿수 배열에 저장하는거
typedef long long intt;                //롱롱 ->인뜨

//--------------------------------------------------------------------------------------------------------–--------

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, result = 0;
    cin >> x;
    for (int i = x; i > 0; i--) {
        if (i < 100) {
            result++;
            continue;
        }
        int jari = 1, yes = 1;
        while (pow(10, jari) <= i)
            jari++;
        int jarisu[4], dif[4];
        inttojari(i, jarisu);
        for (int ii = 0; ii < jari - 1; ii++) {
            dif[ii] = jarisu[ii + 1] - jarisu[ii];
            if (ii != 0 && dif[ii] == dif[ii - 1])
                yes++;
        }
        if (yes == jari - 1) {
            result++;
        }
    }
    cout << result;
}

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