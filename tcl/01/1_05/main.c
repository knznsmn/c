/*****************************************************************************/
/*   1_5/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 19:07:34                                            */
/*   Updated: 2026/01/01 19:35:30                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>

/*
  Exercise 1-4. Write a program to print the corresponding Celsius to
  Fahrenheit table.

  °F = (9/5) (C + 32)
*/

int main(void)
{
  float celsius = 0,
        fahrenheit;

  const int upper = 300;
  const int step  = 20;

  printf("  °C\t °F\n");
  for (int i = 0; i <= upper; i += step)
  {
    fahrenheit = 9.0 / 5 * celsius + 32;
    printf("  %3.0f\t%3.2f\n", celsius, fahrenheit);
    celsius += step;
  }

  return 0;
}

