#include <unistd.h>
#include "strings.c"

void ft_putchar(char c) {
  write(1, &c, 1);
}
void ft_print(char *s) {
  int length = ft_strlen(s);
  write(1, s, length);
}

int main() {

  char a = 42;
  ft_putchar(a);
  ft_putchar('\n');
  ft_print("Wow what the hell!\n");
}
