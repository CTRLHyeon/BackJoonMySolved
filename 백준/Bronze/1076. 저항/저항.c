#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}		//퀵소트용 비교함수(오름차)

int stone[200000];
int up[100000] = { 0 };
int down[100000] = { 0 };

int main() {
	char color[10][10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	char what[10][10];
	int num[3];
	for (int i = 0; i < 3; i++) {
		scanf("%s", what[i]);
		for (int j = 0; j < 10; j++) {
			if (strcmp(what[i],color[j])==0)
				num[i] = j;
		}
	}
	printf("%lld", (10 * num[0] + num[1]) * (long long int)pow(10, num[2]));

}