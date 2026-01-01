/*****************************************************************************/
/*   1_8/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 20:05:55                                            */
/*   Updated: 2026/01/01 20:24:10                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

/*
  Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

int main(void)
{
  int wc, tb, nl;
  wc = tb = nl = 0;
  int c;

  while((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      ++wc;
    }
    if (c == '\t')
    {
      ++tb;
    }
    if (c == '\n')
    {
      ++nl;
    }
  }
  printf("number of wc:%4d\n", wc);
  printf("number of tb:%4d\n", tb);
  printf("number of nl:%4d\n", nl);
}
