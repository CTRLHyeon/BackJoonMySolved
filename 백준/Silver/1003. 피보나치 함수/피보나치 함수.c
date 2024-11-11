#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}		//퀵소트 오름차
typedef long long bigint;

int main() {
	int T;
	int fib[41] = {0,1};
	for (int i = 2; i < 41; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	/*for (int i = 0; i < 40; i++)
		printf("%d번째 fib: %d\n",i , fib[i]);*/
	scanf("%d", &T);
	for (int a = 0; a < T; a++) {
		int num;
		scanf("%d", &num);						//몇번째 피보나치?
		switch (num) {
		case 0:
			printf("1 0\n");
			break;
		case 1:
			printf("0 1\n");
			break;
		default:
			printf("%d %d\n", fib[num - 1], fib[num]);
		}
	}
}