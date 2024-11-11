#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  //표준입출력
#include <string.h> //문자열
#include <ctype.h>  //문자
#include <stdlib.h> //퀵소트
#include <math.h>   //매스

int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	int temp = v - a;
	if (temp%(a-b) == 0)
		printf("%d", temp / (a - b) + 1);
	else 
	printf("%d", temp / (a - b) + 2);

}