/*****************************************************************************/
/*   1_3/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 18:22:44                                            */
/*   Updated: 2026/01/01 19:07:52                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
/*
  Exercise 1-3. Modify the temperature conversion program to print a heading
  above the table.

  °C = (5/9) (°F - 32)
*/

int main(void)
{
  float fahrenheit,
        celsius,
        lower,
        upper,
        step;

  lower = 0;
  upper = 300;
  step = 20;

  fahrenheit = lower;

  printf("°F to °C Conversion\n\n");
  printf("\t°F\t°C\n");
  while (fahrenheit < upper)
  {
    celsius = (5.0 / 9) * (fahrenheit - 32);
    printf("\t%6.2f %6.0f\n", fahrenheit, celsius);
    fahrenheit += step;

  }
  
  return 0;
}
