#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void moses()
{
  ft_putchar(',');
  ft_putchar(' ');
}

void ft_print_comb(void)
{
  int x;
  int y;
  int z;

  x = '0';
  y = '1';
  z = '1';

  while (x <= '9')
  {
    z++;
    
    if (z > '9')
    {
      y++;
      z = '0';
    }
    if (y > '9')
    {
      x++;
      y = '0';
    }
    if (x == y || x == z || y == z)
    {
      continue;
    }
    else
    {
      ft_putchar(x);
      ft_putchar(y);
      ft_putchar(z);
      if (x == '9' && y == '8' && z == '7')
      {
        ft_putchar('.');
        ft_putchar('\n');
      }
      else
      {
        moses();
      }
    }
  }
}


int main()
{
  ft_print_comb();

  return 0;
}