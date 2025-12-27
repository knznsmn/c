/*****************************************************************************/
/*   003/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@knznsmn.com                                               */
/*   Created: 2025/12/26 20:16:26                                            */
/*   Updated: 2025/12/26 20:16:26                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = malloc(sizeof *p);

  if (p == NULL) {
    return 1;
  }

  *p = 42;
  printf("The value of p is %d.\n", *p);

  free(p);
  p = NULL;

  return 0;
}
