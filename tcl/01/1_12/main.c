/*****************************************************************************/
/*   1_12/main.c                                                             */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/02 10:13:01                                            */
/*   Updated: 2026/01/02 10:29:23                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

/*
  Exercise 1-12. Write a program that prints its input one word per line.
*/

#include <stdio.h>

int main()
{
  int c;
  
  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      putchar('\n');
    }
    else {
      putchar(c);
    }
  }
}
