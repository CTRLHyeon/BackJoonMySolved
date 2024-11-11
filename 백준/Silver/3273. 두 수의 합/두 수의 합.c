#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int num2[10000001] = { 0 };			//수열의 원소가 잇는지 확인하기 위한 배열입니ㅏㄷㅇ
int compare(int* a, int* b) {
	return (*a - *b);
}


int main() {

	int n, result = 0;							//n은 수열 의 크기 이고요, result는 몇개인지 계산해서 출력 할 것 입 니다.!
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);			//수열의 원소 입력받기
		num2[num-1]++;				//수열에 num이 있음
	}

	int x;
	scanf("%d", &x);				//두 수의 합 x를 입력받아용!

	for (int i = 1; i < x; i++) {
		int bosu = x - i;			//보수는 x-i 입니다
		

		if ((num2[i-1]==1)&&(num2[bosu - 1] == 1)) {		//i가 있고 보수가 있으면 result ++ 
			result++;
		}
	}
	printf("%d", result/2);
}
