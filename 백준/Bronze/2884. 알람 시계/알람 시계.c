#include <stdio.h>

int main() {
  int H, M;
  scanf("%d %d", &H, &M);
  if (M >= 45)
    printf("%d %d", H, M-45);
  else
  {
    if (H == 0)
      printf("23 %d", M+15);
    else
      printf("%d %d", H-1, M+15);
  }
}