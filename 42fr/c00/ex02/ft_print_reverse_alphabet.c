#include <unistd.h>

void ft_putchar(char c) {
  write(1, &c, 1);
}

int main() {
  
  int letter = 'z';
  while (letter >= 'a') {
    ft_putchar(letter);
    letter--;
  }
  ft_putchar('\n');
}
