/*****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/10 06:58:18                                            */
/*   Updated: 2026/01/10 06:58:18                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include "utilities.c"


int main(int argc, char **argv) {

  if (argc < 2) {
    ft_puts("Reading data from file.");
    ft_print("Enter the filename: ");
    char filename[BUFFER_SIZE];
    ft_getline(filename);

    int fd = open(filename, O_RDONLY);
    if (!fd) return -1;

    char buffer[BUFFER_SIZE];
    ft_fgets(&fd, buffer);

    ft_print(filename);
    ft_puts(" contents:");
    ft_puts(buffer);
  }
  else {
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (!fd) return -1;
    else {
      ft_print("File \"");
      ft_print(argv[1]);
      ft_puts("\" created successfully.");
    }

    ft_print("What's your name ? ");
    char answer[BUFFER_SIZE];
    ft_getline(answer);
    
    ft_fputs(fd, answer);
    ft_puts("Data inserted successfully.");

    close(fd);
  }

  return 0;
}
