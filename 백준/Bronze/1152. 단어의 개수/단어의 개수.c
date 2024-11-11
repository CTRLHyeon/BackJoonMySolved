#include <stdio.h>
#include <string.h>
char sentence[1000001];
int main() {
	int word=0;
	gets(sentence);
	if(strtok(sentence, " ") != NULL)
		word++;
	while (strtok(NULL, " ") != NULL)
		word++;
	printf("%d", word);
}