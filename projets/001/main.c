/*****************************************************************************/
/*   001/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/04 10:13:41                                            */
/*   Updated: 2026/01/04 15:26:58                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <unistd.h>
#include <fcntl.h>

size_t ft_strlen(const char *s);

int main(int argc, char **argv) {
  char *msg = "Usage: argv[0] <string>\n";
  if (argc != 2) {
    write(1, msg, ft_strlen(msg));
    return 0;
  }

  int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    write(1, "failed", 6);
    return 1;
  }

  char *text = "Jesus I can write to files!";
  write(fd, text, ft_strlen(text));

  close(fd);
  return 0;
}

size_t ft_strlen(const char *s) {

  size_t i = 0;
  while (*(s + i) != '\0') {
    i++;
  }
  return i;
}
