/*****************************************************************************/
/*   005/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/27 16:09:10                                            */
/*   Updated: 2025/12/27 16:09:10                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main(void) {

  int *decint = malloc((sizeof *decint) * SIZE);

  for (int i = 0; i < SIZE; i++) {
    *(decint + i) = (i + 1) * 10;
  }

  for (int i = 0; i < SIZE; i++) {
    printf("%d\n", *(decint + i));
  }

  return 0;
}
