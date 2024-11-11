#include <stdio.h>

int main() {
  int x,y,y1,y2,y3;
  scanf("%d",&x);
  scanf("%d",&y);
  y3 = (y%100)%10;
  y2 = ((y - y3) / 10) % 10;
  y1 = (y - y3 - 10*y2)/100;
  printf("%d\n%d\n%d\n%d", x*y3, x*y2, x*y1, x*y);
  return 0;
}