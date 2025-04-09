#include <unistd.h>

void ft_putchar(char c) {
  write(1, &c, 1);
}

int main() {
  char number = '0';
  while (number <= '9') {
    ft_putchar(number);
    number++;
  }
  ft_putchar('\n');
}
