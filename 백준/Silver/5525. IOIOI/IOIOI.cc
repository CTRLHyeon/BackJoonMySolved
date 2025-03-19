#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int len = 2 * n + 1;
	char* p = (char*)malloc(sizeof(char) * n * 2 + 1);
	for (int i = 0; i <= len; i++) {
		if (i == len)p[i] = '\0';
		else p[i] = (i % 2) ? 'O' : 'I';
	}

	char s[1000001];
	scanf("%s", s);
	int cnt = 0;

	char* point = strstr(s, p);
	while (point != NULL) {
		cnt++;
		*point = 'x';
		point = strstr(s, p);
		//printf("%p\n", point);
	}
	printf("%d", cnt);
}