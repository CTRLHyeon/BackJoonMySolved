#include <stdio.h>	//표준입출력
#include <string.h>	//문자열 라이브러리
#include <ctype.h>	//문자 라이브러리
#include <math.h>	//수학 라이브러리
#include <stdlib.h>	//표준 라이브러리 (atoi, atof, rand, malloc)

char num[1000001];

int main() {
	
	scanf("%s", num);

	if (strlen(num) == 1) {
		if ((num[0] - '0') % 3 == 0)
			printf("0\nYES");
		else printf("0\nNO");
		return 0;
	}

	int score = 0;
	for (int i = 0; num[i]; i++)	
		score += num[i] - '0';
	//printf("처음스코어 %d\n", score);
	
	int istriple = 0;

	int count = 1;

	if (score <= 9) {
		if (score %3 == 0)
			printf("1\nYES");
		else printf("1\nNO");
		return 0;
	}

	while (score >= 10) {
		
			int temp[1000] = { 0 };

			int jari = 0;
			while (score >= (int)pow(10, jari))
				jari++;
			//printf("jari = %d\n", jari);

			for (int i = 0; i < jari; i++) {
				temp[i] = score / pow(10, jari - i-1);
				score -= temp[i] * pow(10, jari - i-1);
				
			}
			//printf("temp : ");

			for (int i = 0; i < jari; i++) {
				//printf("%d ", temp[i]);
				score += temp[i];
			}
			//printf("score : %d\n", score);
			count++;
	}
	//printf("score :%d\n",score);
	if (score %3 ==0) printf("%d\nYES", count);
	else printf("%d\nNO", count);
}
