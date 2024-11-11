#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
char bin[1000001];
int oct[1000001];
int real_oct[1000001];
char temp[1000003] = "\0";

int main() {

	memset(oct, -1, sizeof(oct));
	memset(real_oct, -1, sizeof(real_oct));
	scanf("%s", bin);
	if (strcmp(bin, "0") == 0) {
		printf("0");
		return 0;
	}
	int len = strlen(bin);

	for (int i = 0; i < len; i++)
		temp[len - i-1] = bin[i];

	strcat(temp, "00");

	for (int i = 0; i < len; i += 3) {
		int num = 0;
		if (temp[i] == '1')
			num += 1;
		if (temp[i + 1] == '1')
			num += 2;
		if (temp[i + 2] == '1')
			num += 4;
		oct[i] = num;
	}
	int t = 0;

	for (int i = 1000000; i >= 0; i--)
		if (oct[i] != -1) {
			real_oct[t] = oct[i];
			t++;
		}
	for (int i = 0; i < 1000001; i++) {
		if (i == 0) {
			if (real_oct[i] != 0)
				printf("%d", real_oct[i]);
		}
		else if (real_oct[i] != -1)
			printf("%d", real_oct[i]);
	}
}