#include <math.h>
#include <stdio.h>

#define f1(x,y,z) (17 - y + 2 * z) / 20
#define f2(x,y,z) (-18 -3 * x + z) / 20
#define f3(x,y,z) (25 -2 * x + 3 * y) /20// Below is the the equations in non-row dominant form

int main() {// declaring variable with initial guess...
  float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e = 0.001; 
  int count = 1;

  printf("\nCount\tx\ty\tz\n");
  do {
    x1 = f1(x0, y0, z0);
    y1 = f2(x1, y0, z0);
    z1 = f3(x1, y1, z0);

    printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

    e1 = fabs(x0 - x1); 
    e2 = fabs(y0 - y1);
    e3 = fabs(z0 - z1);

    count++;

    x0 = x1;
    y0 = y1;
    z0 = z1;
  } while (e1 > e && e2 > e && e3 > e);
  
  printf("\nSolution: x = %0.3f, y=%0.3f and z = %0.3f\n", x1, y1, z1);

  return 0;
}
/* A system of linear equations in diagonally dominant form: 
20x + y - 2z = 17 
3x + 20y -z = -18 
2x - 3y + 20z = 25 Defining the functions */
// #define f1(x, y, z) (25 + 3 * y - 20 * z) / 2
// #define f2(x, y, z) 17 + 2 * z - 20 * x
// #define f3(x, y, z) 3 * x + 20 * y + 18 // When these three equation are taken then the output diverges
/*
Normal output:
Count   x       y       z
1       0.8500  -1.0275 1.0109
2       1.0025  -0.9998 0.9998
3       1.0000  -1.0000 1.0000

Solution: x = 1.000, y=-1.000 and z = 1.000

Output when x = 1, y = -0.88 annd z = 1
Count   x       y       z
1       0.9940  -0.9991 1.0007

Solution: x = 0.994, y=-0.999 and z = 1.001
*/