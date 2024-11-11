#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int upcmp(int* a, int* b) {
	return (*a - *b);
}		//퀵소트 오름차
int downcmp(int* a, int* b) {
	return (*b - *a);
}		//퀵소트 내림차
int maxnum(int a, int b) {
	return (a >= b) ? a: b;
}		//최댓값 반환 함수
typedef long long intt;	//롱롱 -> intt

int main() {
	int T;
	scanf("%d", &T);
	intt dp[101] = { 0,1,1,1,2,2,3 };
	for (int i = 7; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	//for (int i = 1; i < 101; i++)
		//printf("%lld\n", dp[i]);

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}