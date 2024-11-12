#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
///---------------------------------------------------------
//오름차 : <
//내림차 : >
void swap(char* m[50], int a, int b);
int main() {
    int a, b, cnt = 0;
    scanf("%d %d", &a, &b);

    char m[50][51], n[50][51];
    for (int i = 0; i < a; i++)
        scanf("%s", m[i]);
    for (int i = 0; i < a; i++)
        scanf("%s", n[i]);

    for (int i = 0; i <= a - 3; i++) {
        for (int j = 0; j <= b - 3; j++) {
            if (m[i][j] != n[i][j]) {

                for (int ii = i; ii < i + 3; ii++) {
                    for (int jj = j; jj < j + 3; jj++) {
                        if (m[ii][jj] == '0')
                            m[ii][jj] = '1';
                        else if (m[ii][jj] == '1')
                            m[ii][jj] = '0';
                    }
                }
                cnt++;
                //printf("\n\n바꾼거\n");
                //for (int i = 0; i < a; i++) {
                //    printf("%s\n", m[i]);
                //}
            }
        }
    }

    int dif=0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (m[i][j] != n[i][j])
                dif = 1;
        }
    }
    if (dif) printf("-1");
    else printf("%d", cnt);
}

void swap(char* m[50], int a, int b) {
    for (int i = a; i < a + 3; i++) {
        for (int j = b; j < b + 3; j++) {
            if (m[i][j] == '0')
                m[i][j]++;      //'0'을 '1'로
            else m[i][j]--;     //'1'을 '0'으로
        }
    }
}