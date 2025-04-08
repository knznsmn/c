#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_is_negative(int n) {

	if (n % 2 == 0) {
		ft_putchar('Y');
	}
	else {
		ft_putchar('N');
	}
}


int main()
{
	ft_is_negative(42);
	ft_putchar('\n');
}