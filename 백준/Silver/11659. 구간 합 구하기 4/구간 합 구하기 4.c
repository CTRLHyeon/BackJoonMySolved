#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}		//퀵소트용 비교함수(오름차)

int num[100000];

int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 1; i < n; i++)
		num[i] += num[i - 1];
	for (int i = 0; i < m; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		start--;
		end--;
		printf("%d\n", num[end] - num[start - 1]);
	}
}
