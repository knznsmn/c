#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_moses(char c)
{
	if (c == 'e')
	{
		ft_putchar('.');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
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
		ft_putchar(n);
		if (n >= '9')
		{
			m++;
			n = '0';
		}
		if (m == '9' && n == '9')
		{
			y++;
			m = '0';
			n = '0';
		}
		if (y > '9')
		{
			x++;
			y = '0';
		}
		
		if (m == '9' && n == '9')
		{
			ft_moses('e');
		}
		else
		{
			ft_moses('n');
		}
		n++;
	}
}

int main()
{
	ft_print_comb2();
}