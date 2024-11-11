#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int mush[10], sum = 0, little, large=500;
	for (int i = 0; i < 10; i++)
		scanf("%d", &mush[i]);
	int repeat = 0;
	for (int i = 0; i < 10; i++)
	{
			sum += mush[i];
			little = sum;
		if (sum > 100) {
			little -= mush[i];
			large = sum;
			break;
		}
	}
	if (100 - little > large - 100)
		printf("%d", large);
	else if (100 - little == large - 100)
		printf("%d", large);
	else printf("%d", little);
}