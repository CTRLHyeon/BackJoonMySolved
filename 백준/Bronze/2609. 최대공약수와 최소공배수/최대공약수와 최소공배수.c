#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
	int a, b, min, max;
	scanf("%d %d", &a, &b);
	if (b > a) {
		int temp = b;
		b = a; 
		a = temp;
	}
	int tempa = a;
	int tempb = b;
	min = tempa % tempb;
	while (min != 0) {
		tempa = tempb;
		tempb = min;
		min = tempa % tempb;
	}
	min = tempb;
	max = a * b / min;
	printf("%d\n%d", min, max);
}