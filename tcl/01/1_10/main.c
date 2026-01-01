/*****************************************************************************/
/*   1_10/main.c                                                             */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 20:43:57                                            */
/*   Updated: 2026/01/01 21:06:13                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

/*
  Exercise 1-10. Write a program to copy its input to its output, replacing
  each tab by \t, each backspace by \b, and each backslash by \\. This makes
  tabs and backspaces visible in an unambiguous way.
*/

#include <stdio.h>

int main()
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\b')
    {
      c = '\\';
      putchar(c);
      putchar('b');
    }
    else if (c == '\\')
    {
      putchar('\\');
      putchar('\\');
    }

    else
    {
      putchar(c);
    }
  }
}
