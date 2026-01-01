/*****************************************************************************/
/*   1_6/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 19:35:36                                            */
/*   Updated: 2026/01/01 19:45:23                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>

/*
  Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
*/

int main()
{
  int c;
  c = getchar() != EOF;
    printf("getchar() = EOF is %d.\n", c);
}
