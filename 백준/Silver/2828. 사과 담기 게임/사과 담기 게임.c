#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int num1[100000];
int num2[100000];
int compare(int* a, int* b) {
	return (*a - *b);
}
int main() {
	int n, m, j, result = 0, width;
	scanf("%d %d", &n, &m);
	width = m;
	scanf("%d", &j);
	for (int i = 0; i < j; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp - m > 0) {			// 사과가 오른쪽에 떨어진다. m은 바구니의 가장 오른쪽의 좌표
			result += temp - m;
			m = temp;
		}
		else if (temp - (m - width + 1) < 0) {	// 사과가 왼쪽에 떨어진다. m은  바구니 가장 왼쪽의 좌표 (= 가장 오른쪽의 좌표 - width + 1)
			result += (m - width + 1) - temp;			//elif 조건문은 temp가 m보다 작다
			m = (temp + width - 1);
		}
	}
	printf("%d", result);
}
