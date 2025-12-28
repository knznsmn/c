/*****************************************************************************/
/*   004/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/27 15:14:27                                            */
/*   Updated: 2025/12/27 15:14:27                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int *create_int(int value);

int main(void) {
  int *test = create_int(1337);
  if (test == NULL) {
    return 1;
  }
  printf("Test call result: %d.\n", *test);

  free(test);
  test = NULL;

  return 0;
}

int *create_int(int value) {

  int *x = malloc(sizeof *x);

  if (x == NULL) {
    return NULL;
  }

  *x = value;
  return x;
}
