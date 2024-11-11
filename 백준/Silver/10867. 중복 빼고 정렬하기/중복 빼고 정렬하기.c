#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int num[100000];
int compare(int* a, int* b) {
	return (*a - *b);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), compare);
	for (int i = 0; i < n; i++) {
		if (i == 0)
			printf("%d ", num[i]);
		else if (num[i - 1] != num[i])
			printf("%d ", num[i]);
	}
}
