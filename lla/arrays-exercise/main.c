/*****************************************************************************/
/*   arrays-exercise/main.c                                                  */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@knznsmn.com                                               */
/*   Created: 2025/09/26 22:24:53                                            */
/*   Updated: 2025/09/27 07:35:18                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#define MAX 10

int main(int argc, char **argv) {

  int myarrays[MAX] = {0};
  for (int i = 0; i < MAX; i++) {
    printf("%d", myarrays[i]);
    if (i == MAX - 1) {
      printf(".\n");
    }
    else {
      printf(", ");
    }
  }
  printf("Setting 4th element to 2...\n\n");
  printf("Printing the new array...\n");
  myarrays[3] = 2;
  for (int i = 0; i < MAX; i++) {
    printf("%d", myarrays[i]);
    if (i == MAX - 1) {
      printf(".\n");
    }
    else {
      printf(", ");
    }
  }
  return 0;
}
