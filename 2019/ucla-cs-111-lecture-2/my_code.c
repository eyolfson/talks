#include <stdio.h>
#include <stdlib.h>

#include "libpoint.h"

int main(int argc, char **argv)
{
  struct point *p = malloc(sizeof(struct point));
  p->x = 3;
  p->y = 4;
  printf("p.x = %d\n", p->x);
  squareX(p);
  printf("p.x = %d\n", p->x);
  return 0;
}
