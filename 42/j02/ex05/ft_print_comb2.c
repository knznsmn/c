#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb2()
{
	int x;
	int y;
	int m;
	int n;
	x = '0';
	y = '0';
	m = '0';
	n = '0';
	while (x <= '9')
	{
		ft_putchar(x);
		ft_putchar(y);
		ft_putchar(' ');
		ft_putchar(m);
		if (n > '9')
		{
			m++;
			ft_putchar(n);
			n = '0';
		}
		else if (m == '9' && n == '9')
		{
			y++;
			ft_putchar(n);
			m = '0';
			n = '0';
		}
		else if (y > '9')
		{
			x++;
			y = '0';
		}
		else {
			ft_putchar(n);
			n++;	
		}
		ft_putchar(',');
		ft_putchar(' ');
		
		
	}
}

int main()
{
	ft_print_comb2();
}
