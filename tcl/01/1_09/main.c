/*****************************************************************************/
/*   1_09/main.c                                                             */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 20:27:01                                            */
/*   Updated: 2026/01/01 20:43:29                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>

/*
  Exercise 1-9. Write a program to copy its input to its output,
  replacing each string of one or more blanks by a single blank.
*/

int main()
{
  int c;
  int wc = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      wc++;
      if (wc == 2)
      {
        c = '\b';
        wc = 0;
      }
    }
    putchar(c);
  }
}
