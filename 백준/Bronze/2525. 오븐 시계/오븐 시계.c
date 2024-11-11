#include <stdio.h>

int main() {
  int A, B, C;
  scanf("%d %d", &A, &B);
  scanf("%d", &C);
  B += C;
    while (B >= 60){
      A++;
      B -=60;
    }
    if (A >= 24)
      A -= 24;
  printf("%d %d", A, B);
}