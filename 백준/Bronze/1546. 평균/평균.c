#include <stdio.h>
int main() {
	int gesu;
	float x, exam[1000], average=0;
	scanf("%d ", &gesu);
	for (int i = 0; i < gesu; i++) {
		scanf("%f", &x);
		exam[i] = x;
	}
	float max = 0;
	for (int i = 0; i < gesu; i++) {
		if (exam[i] > max)
			max = exam[i];
	}
	for (int i = 0; i < gesu; i++) {
		exam[i] = exam[i] / max * 100;
		average += exam[i];
	}
	average /= gesu;
	printf("%f", average);
}