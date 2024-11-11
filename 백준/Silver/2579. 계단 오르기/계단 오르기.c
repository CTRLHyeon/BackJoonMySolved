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
	int n;
	scanf("%d", &n);

	int stair[301];						//계단당 점수
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}									//입력


	int dp[301];					//총 점수
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = maxnum(stair[1], stair[2]) + stair[3];		//maxnum은 최댓값 반환하는거
	for (int i = 4; i <= 300; i++)
		dp[i] = maxnum(dp[i - 2], stair[i-1] + dp[i - 3]) + stair[i];
	printf("%d", dp[n]);
}