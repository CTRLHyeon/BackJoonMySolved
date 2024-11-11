#include <stdio.h>
#include <string.h>

int main() {
	int number[16], sec=0;
	char word[16] = {};
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++) {
		switch (word[i]) {
		case 'A':
		case 'B':
		case 'C':
			number[i] = 2;
			break;
		case 'D':
		case 'E':
		case 'F':
			number[i] = 3;
			break;
		case 'G':
		case 'H':
		case 'I':
			number[i] = 4;
			break;
		case 'J':
		case 'K':
		case 'L':
			number[i] = 5;
			break;
		case 'M':
		case 'N':
		case 'O':
			number[i] = 6;
			break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			number[i] = 7;
			break;
		case 'T':
		case 'U':
		case 'V':
			number[i] = 8;
			break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			number[i] = 9;
			break;
		}
	}
	for (int i = 0; i < strlen(word); i++)
		sec += number[i] + 1;
	printf("%d", sec);
}