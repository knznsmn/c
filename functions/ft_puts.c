#include "strings.c"


void ft_puts(char *s) {
  int length = ft_strlen(s);
  write(1, s, length);
}

int main() {

  char a = 42;
  ft_putchar(a);
  ft_putchar('\n');
  ft_puts("Wow what the hell!\n");
}
