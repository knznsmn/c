#include <unistd.h>
#define BUFFER_SIZE 32

void ft_putchar(char c) {
  write(1, &c, 1);
}
int ft_strlen(char *s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

int main(int argc, char **argv) {
  char *msg_1 = "\nUsage: ";
  char *msg_2 = " <char>\n";
  if (argc < 2) {
    write(1, msg_1, ft_strlen(msg_1));
    write(1, argv[0], ft_strlen(argv[0]));
    write(1, msg_2, ft_strlen(msg_2));
    ft_putchar('\n');
  }
  else {
    ft_putchar(argv[1][0]);
    ft_putchar('\n');
  }
}
