#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  int nai, mom;
  char name[20];
  while (1){
  scanf("%s %d %d",name, &nai, &mom);
  if (strcmp(name,"#")==0)
    return 0;
  else if (nai >=18 || mom>=80)
    printf("%s Senior\n",name);
  else
    printf("%s Junior\n",name);
  }
}