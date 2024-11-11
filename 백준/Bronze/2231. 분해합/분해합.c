#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n+1; i++){
    int jari=0;
    int result=i;
    while (pow(10,jari)<=i)
      jari++;//자릿수 구하기
    int temp = i;
    for (int j=jari; j>0; j--){
      result += temp / (int)pow(10,j-1);
      temp -= temp/(int)pow(10,j-1)*(int)pow(10,j-1);
      
    //printf("i: %d, added %d(자릿수) to result: %d\n",i, temp,result);
    }
    if (result == n){
      printf("%d", i);
      return 0;
    }
  }
  printf("0");
}