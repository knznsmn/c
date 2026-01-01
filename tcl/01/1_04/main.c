/*****************************************************************************/
/*   1_4/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 18:48:58                                            */
/*   Updated: 2026/01/01 19:07:59                                            */
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
  float celsius,
        fahrenheit;
  float lower,
        upper,
        step;

  lower = 0;
  upper = 300;
  step  = 20;

  celsius = lower;
  printf("  °C\t °F\n");
  while (celsius <= upper)
  {
    fahrenheit = 9.0 / 5 * celsius + 32;
    printf("  %3.0f\t%3.2f\n", celsius, fahrenheit);
    celsius += step;
  }

  return 0;
}
