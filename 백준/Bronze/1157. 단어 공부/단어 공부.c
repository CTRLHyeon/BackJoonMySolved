#include <stdio.h>
#include <string.h>
#include <ctype.h>

char word[1000000];

int main() {
	int alpha[26] = { 0 }, max = 0, maxgesu = 1, maxbun = 0, giri;
	scanf("%s", word);
	giri = strlen(word);
	for (int i = 0; i < giri; i++)
		if (islower(word[i]))
			word[i] = toupper(word[i]);
	//여기까진 잘됨~
	for (int i = 0; i < giri; i++) {
		alpha[word[i] - 65]++;
	}
	
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			maxgesu = 1;
			max = alpha[i];
			maxbun = i;
		}
		else if (alpha[i] == max)
			maxgesu += 1;
	}
	if (maxgesu != 1)
		printf("?");
	else
		printf("%c", maxbun + 65);
}