#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}		//퀵소트 오름차


int main() {
	int L;			//수열의 크기
	int arr[50];	//수열
	int n;			//포함해야하는 수
	int start=0, end=1001;
	int result = 0;
	scanf("%d", &L);
	for (int i = 0; i < L; i++)
		scanf("%d", &arr[i]);
	qsort(arr, L, sizeof(int), compare);
	scanf("%d", &n);


	for (int i = 0; i < L; i++) {		//해당 for문은 n을 포함하는 범위를 찾음
		if (arr[i] == n) {				//n보다 이전의 가장 큰 수는 start, n 다음으로 큰 수는 end
			printf("0");
			return 0;
		}								//n이 수열의 임의의 원소와 같으면 0 출력.

		else if (arr[i] < n)
			start = arr[i];

		else if (arr[i]>n) {
			end = arr[i];
			break;
		}
	}									//여기까지 범위를 찾았다.
	for (int i = start + 1; i < end; i++) {
		for (int j = i + 1; j < end; j++) {
			if (i <= n && j>=n) {
				//printf("[%d,%d]\n", i, j);
				result++;
			}
		}
	}
	printf("%d", result);
}
