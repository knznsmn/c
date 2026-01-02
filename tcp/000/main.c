/*****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/02 15:37:56                                            */
/*   Updated: 2026/01/02 15:37:56                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {
  
  time_t now;
  struct tm *clock;
  int hour;
  char *user = "knznsmn";

  time(&now);
  clock = localtime(&now);
  hour = clock->tm_hour;

  printf("Good ");
  if (hour < 12) {
    printf("morning");
  }
  else if (hour < 18) {
    printf("afternoon");
  }
  else if (hour <24) {
    printf("evening");
  }
  printf(", %s.\n", user);

  return 0;
}
