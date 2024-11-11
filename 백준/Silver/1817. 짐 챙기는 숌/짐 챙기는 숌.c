#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  //표준입출력
#include <string.h> //문자열
#include <ctype.h>  //문자
#include <stdlib.h> //퀵소트
#include <math.h>   //매스

int main() {
    int N, M, sum = 0, box = 1;
    int weight[50];
    scanf("%d %d", &N, &M);

    if (N == 0) {
        printf("0");
        return 0;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &weight[i]);
        sum += weight[i];
    }

    int temp = M;
    for (int i = 0; i<N; i++) {
        if (weight[i] <= temp)
            temp -= weight[i];
        else {
            box++;
            temp = M;
            temp -= weight[i];
        }
    }
    printf("%d", box);
}