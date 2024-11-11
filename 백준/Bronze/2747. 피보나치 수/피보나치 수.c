#include <stdio.h>
#include <string.h>
int sum;
int main (){
    int n, temp0=0, temp1=1;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        if (n == 0)
            sum = 1;
        else{
            sum = temp0+temp1;
            temp1 = temp0;
            temp0 = sum;
        }
    }
    printf("%d",sum);
}
