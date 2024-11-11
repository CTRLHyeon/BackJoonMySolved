#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int upcmp(const void* a, const void* b);					//퀵소트 오름차
int downcmp(const void* a, const void* b);				//퀵소트 내림차
void inttojari(int num, int jarisu[]);		//자릿수 배열에 저장하는거
typedef long long intt;						//롱롱 ->인뜨

//--------------------------------------------------------------------------------------------------------

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, times[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> times[i];
	qsort(times, n, sizeof(int), upcmp);
	for (int i = 1; i < n; i++)
		times[i] += times[i - 1];
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += times[i];
	cout << sum;
}

//--------------------------------------------------------------------------------------------------------
int upcmp(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	return (arg1 > arg2) - (arg1 < arg2);  // arg1이 더 크면 양수, arg2가 더 크면 음수, 같으면 0
}

int downcmp(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	return (arg2 > arg1) - (arg2 < arg1);  // arg2가 더 크면 양수, arg1이 더 크면 음수, 같으면 0
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
