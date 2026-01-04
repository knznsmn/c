/*****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/04 20:15:51                                            */
/*   Updated: 2026/01/04 20:15:51                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

size_t ft_strlen(const char *s) {
  if (!s) {
    return 0;
  }
  size_t i = 0;
  while (*(s + i) != '\0') {
    i++;
  }
  return i;
}
void ft_putchar(const char c) {
  write(1, &c, 1);
}
void ft_puts(const char *s) {
  write(1, s, ft_strlen(s));
}

int main(int argc, char **argv) {

  if (argc < 2) {
    ft_putchar('\n');
    ft_puts("Usage: ");
    ft_puts(argv[0]);
    ft_puts(" <filename>\n\n");
    return 1;
  }
  else {
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
      ft_puts("File creation failed.\n");
      close(fd);
      return 1;
    }
    char *msg = "File successfully created.\n";
    write(fd, msg, ft_strlen(msg));

    close(fd);
  }

  return 0;
}
