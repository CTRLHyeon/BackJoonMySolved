#include <stdio.h>
#include <string.h>
#include <ctype.h>

char word[1000000];

int main() {
	int x, y, w, h, chaix, chaiy, jungdab;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	chaix = w - x;
	chaiy = h - y;
	if (chaix > x)
		chaix = x;
	if (chaiy > y)
		chaiy = y;
	if (chaix > chaiy)
		jungdab = chaiy;
	else
		jungdab = chaix;
	printf("%d", jungdab);
}