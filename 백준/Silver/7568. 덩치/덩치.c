#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}		//퀵소트용 비교함수(오름차)


int main() {
	int n, ki[50], mom[50];
	int tier[50], grade[51] = { 0 }, tlqkf[50] = { 0 }, count[50] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &mom[i], &ki[i]);	//키 몸무게 입력 ㅋㅋ
	for (int i = 0; i < n; i++) {
		int higher = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (ki[i] < ki[j] && mom[i] < mom[j])
					higher++;
			}
		}
		printf("%d ", higher+1);
	}
}