/*****************************************************************************/
/*   002/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/26 11:50:41                                            */
/*   Updated: 2025/12/26 11:50:41                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>

int main(void) {
  int result = 7 * 13;
  size_t sizeof_int = sizeof(int);
  size_t sizeof_float = sizeof(float);
  size_t sizeof_double = sizeof(double);

  printf("Hello, knznmns!\n");
  printf("7 x 13 = %d\n", result);
  printf("The size of int is: %zu.\n", sizeof_int);
  printf("The size of float is: %zu.\n", sizeof_float);
  printf("The size of double is: %zu.\n", sizeof_double);

  int x = 0;
  int *p = &x;

  x = 42;
  y = 

  printf("The value of x = %d.\n", x);
  printf("The address of x is %p.\n", (void *)&x);
  printf("The value of p is %p.\n",(void *)p);
  printf("The value pointed to by p is %d.\n",*p);

  return 0;
}
