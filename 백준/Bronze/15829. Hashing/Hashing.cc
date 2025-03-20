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
	int hash[50];
	intt result=0;
	char word[51];
	int len;
	cin >> len;
	cin >> word;
	for (int i = 0; word[i]; i++) {
		intt temp = 1;
		hash[i] = word[i] - 'a' + 1;
		for (int j = 0; j < i; j++) {
			temp *= 31;
			if (temp > 1000000000000)
				temp %= 1234567891;
		}
		result += temp * hash[i];
	}
	cout << result % 1234567891;

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