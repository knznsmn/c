#include <unistd.h>

int ft_strlen(char *s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

void ft_puts(char *s) {
  int length = ft_strlen(s);
  write(1, s, length);
}

int main() {

  ft_puts("Wow what the hell!\n");
}
