#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}		//퀵소트 오름차

long long factorial(int num);

int main() {
	int result = 0;
	long long n;
	scanf("%lld", &n);
	if (n == 0) {
		printf("NO");
		return 0;
	}
	long long fact[21] = { 0 };
	for (int i = 0; i < 20; i++){
		fact[i] = factorial(i);		//fact 배열 초기화
		if (n == fact[i]) {
			printf("YES");
			return 0;
		}
	}
	fact[20] = 1000000000000000001;
	int count=0;
	while (1) {
		if (n > fact[count])
			count++;
		else break;
	}
	//printf("%d", count);

	long long temp = n;
	for (int i = count; i >= 0; i--) {
		if (temp >= fact[i]) {
			temp -= fact[i];
			//printf("diminished fact[%d](%lld), current : %lld\n", i, fact[i], temp);
		}
	}
	(temp == 0) ? printf("YES") : printf("NO");
}

long long factorial(int num) {
	if (num == 0)
		return 1;
	else
		return num * factorial(num - 1);
}
