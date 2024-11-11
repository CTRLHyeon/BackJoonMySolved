#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//백준 1018번 클래스2 문제

int main() {
	int r[2] = { 0 }, g[2] = { 0 }, b[2] = { 0 }, y[2] = { 0 }, result=0;
	char color[11];
	char compare[11];

	scanf("%s", color);
	for (int i = 0; i < 10; i++) {
		switch (color[i])
		{
		case 'R':
			r[0]++;
			break;
		case 'G':
			g[0]++;
			break;
		case 'B':
			b[0]++;
			break;
		case 'Y':
			y[0]++;
			break;
		default:
			break;
		}
	}
	//printf("original RGBY: %d %d %d %d\n", r[0], g[0], b[0], y[0]);
	scanf("%s", compare);
	for (int i = 0; i < 10; i++) {
		switch (compare[i])
		{
		case 'R':
			r[1]++;
			break;
		case 'G':
			g[1]++;
			break;
		case 'B':
			b[1]++;
			break;
		case 'Y':
			y[1]++;
			break;
		default:
			break;
		}
	}
	//printf("comparing RGBY: %d %d %d %d\n", r[1], g[1], b[1], y[1]);
	//rgby
	r[0] -= r[1];
	g[0] -= g[1];
	b[0] -= b[1];
	y[0] -= y[1];
	if (r[0] > 0)
		result += r[0];
	if (g[0] > 0)
		result += g[0];
	if (b[0] > 0)
		result += b[0];
	if (y[0] > 0)
		result += y[0];
	printf("%d", result);
}