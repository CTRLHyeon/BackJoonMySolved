#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	char* IO = (char*)malloc(sizeof(char) * (2 * n + 1));
	char* s = (char*)malloc(sizeof(char) * m);

	for (int i = 0; i < 2 * n + 1; i++) {
		if (i % 2)IO[i] = 'O';
		else IO[i] = 'I';
	}										//IOIOI... 초기화
	IO[2 * n + 1] = '\0';
	int cnt = 0;
	scanf("%s", s);
	char* temp = strstr(s, IO);
	while (temp != NULL) {
		cnt++;
		*temp = '\b';
		temp = strstr(s, IO);
	}
	printf("%d", cnt);
}