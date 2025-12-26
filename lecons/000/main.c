/*****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@knznsmn.com                                               */
/*   Created: 2025/12/26 10:17:43                                            */
/*   Updated: 2025/12/26 10:17:43                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int result = 7 * 13;
  size_t sizeof_int = sizeof(int);
  size_t sizeof_float = sizeof(float);
  size_t sizeof_double = sizeof(double);

  printf("Hello, knznmns!\n");
  printf("7 x 13 = %d\n", result);
  printf("The size of int is: %zu\n", sizeof_int);
  printf("The size of float is: %zu\n", sizeof_float);
  printf("The size of double is: %zu\n", sizeof_double);

  return 0;
}

