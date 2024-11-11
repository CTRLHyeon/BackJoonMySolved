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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, wait[1000], temp, friends[1000] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> wait[i];

	for (int i = 0; i < m; i++) {
		cin >> temp;
		for (int j = 0; j < n; j++) {
			if (temp == wait[j]) {
				friends[j] = 1;
			}
			
		}
	}
	int startcount = 0, result = 0;
	for (int i = 0; i < m; i++) {
		if (friends[i] == 0) {
			result++;
		}
	}
	cout << result;
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