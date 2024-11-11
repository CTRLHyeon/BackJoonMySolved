#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int upcmp(int* a, int* b);					//퀵소트 오름차
int downcmp(int* a, int* b);				//퀵소트 내림차
void inttojari(int num, int jarisu[]);		//자릿수 배열에 저장하는거
typedef long long intt;						//롱롱 ->인뜨

//--------------------------------------------------------------------------------------------------------

int main() {
	int t;
	cin >> t;
	while (t-- != 0) {
		int n;
		cin >> n;
		int pro = 1;
		for (int i = 1; i <= n; i++) {
			pro *= i;
			while (pro % 10 == 0)
				pro /= 10;
			if (pro > 10000)
				pro %= 10000;
		}
		cout << pro%10 << '\n';
	}
}

//--------------------------------------------------------------------------------------------------------
int upcmp(int* a, int* b) {
	return (*a - *b);
}
int downcmp(int* a, int* b) {
	return (*b - *a);
}
void inttojari(int num, int jarisu[]) {
	int jari = 0;
	int temp = num;
	for (int i = 0; pow(10, i) <= num; i++)
		jari++;
	for (int i = jari; i > 0; i--) {
		jarisu[jari-i] = temp / (int)pow(10, i - 1);
		temp -= temp / (int)pow(10, i - 1) * (int)pow(10, i - 1);
	}
}