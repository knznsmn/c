#include <unistd.h>

void ft_putchar(char c) {
  write(1, &c, 1);
}

int main() {
  char letter = 'a';
  while (letter <= 'z') {
    ft_putchar(letter);
    letter++;
  }
  ft_putchar('\n');
}
