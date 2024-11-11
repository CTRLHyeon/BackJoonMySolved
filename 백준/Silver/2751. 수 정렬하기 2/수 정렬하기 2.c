#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int arr[1000000];
int compare(int* a, int* b);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}

int compare(int* a, int* b) {
	return *a - *b;
}
