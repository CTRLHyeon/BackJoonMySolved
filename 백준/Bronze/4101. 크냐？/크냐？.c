#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  int a,b;
  for (int i=0; 1; i++){
    scanf("%d %d", &a, &b);
    if (a==0 && b==0)
      return 0;
    (a>b)?printf("Yes\n"): printf("No\n");
  }

}