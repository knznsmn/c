/*****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/31 09:48:23                                            */
/*   Updated: 2025/12/31 11:23:03                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>

int ft_strlen(char *s);

int main(int argc, char **argv) {

  if (argc < 2 || argc > 2) {
    printf("Usage: %s: <string>\n", *argv);
  }
  else {
    printf("%s is %d characters long.\n", *(argv + 1), ft_strlen(*(argv + 1)));
  }


  return 0;
}

int ft_strlen(char *s) {
  if (s == NULL) {
    return 1;
  }
  int length = 0;
  for (int i = 0; *(s + i) != '\0'; i++) {
    length = i + 1;
  }
  return length;
}
