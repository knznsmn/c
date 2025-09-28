/*****************************************************************************/
/*   strings-exercise/main.c                                                 */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@knznsmn.com                                               */
/*   Created: 2025/09/27 07:33:55                                            */
/*   Updated: 2025/09/27 07:33:55                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

  char *str = "hehe";
  char chch[] = {'h', 'e', 'h', 'e', '\0'};
  char chc[] = {"hehe"};

  if (strcmp(chc, chch)) {
    printf("Yay!\n");
  }
  else {
    printf("Nay!\n");
  }
  return 0;
}
