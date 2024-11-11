#include <stdio.h>

int main() {
  double x, y;
  scanf("%lf %lf", &x, &y);
  printf("%.9lf", x / y);
  return 0;
}