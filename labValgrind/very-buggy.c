#include <stdlib.h>
#include <stdio.h>

static void* return_arg(void* p);
int frame3 ( void )
{
  int *a = malloc(10 * sizeof(int));
  int n = a[9];
  int i;

  for(i=0;i<9;i++){
	a[i] = i*5;
  }

  if (a[5] == 42) {
    printf("hello from frame3().  The answer is 42.\n");
  } else {
    printf("hello from frame3().  The answer is not 42.\n");
  }

  n = a[  a[0] & 7  ];

  free(a);

  a = malloc(99 * sizeof(int));

  free(a);
  return n;
}

int frame2 ( void )
{
  return frame3() - 1;
}

int frame1 ( void )
{
  return frame2() + 1;
}

int main ( void )
{
  return frame1() - 1;
}

static void* return_arg(void* p)
{
   return p;
}

