#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}		//퀵소트 오름차

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int temp = i;
		yes:
		if (temp % 5 == 0) {
			while (temp / 5 >= 1) {
				sum++;
				temp /= 5;
				//printf("current i: %d, sum++ed. temp: %d\n", i, temp);
				goto yes;
			}
		}
	}
	printf("%d", sum);
}
