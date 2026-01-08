/****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/04 20:15:51                                            */
/*   Updated: 2026/01/04 20:15:51                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include "headers.c"

void hr(const Header *hr, int *f);
void rw(const Header *hr, int *f, struct *t, char *s);

typedef struct {
  char *name;
  char *info;
} Detail;

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
    
    Header *header = create_hr(argv[1]);
    Detail name;
    Detail mail;
    ft_strcpy(name.name, "By:");
    ft_strcpy(name.info, "knznsmn");
    ft_strcpy(mail.name, "Email");
    ft_strcpy(mail.info, "mail@jccesar.com");

    hr(header, &fd);
    hr(header, &fd);
    rw(header, &fd, name, argv[1]);
    rw(header, &fd, mail, argv[1]);


    
    destroy_hr(&header);
    close(fd);
  }
  return 0;
}


void hr(const Header *hr, int *f) {
  if (hr == NULL || f == -1) return;

  int number_of_hr_lines = 75;
  if (ft_strcmp(hr->hr_extf, ".lua")) {
    number_of_hr_lines = 73;
  }
  else if (ft_strcmp(hr->hr_extf, ".html")) {
    number_of_hr_lines = 72;
  }

  write(*f, hr->hr_open, ft_strlen(hr->hr_open));
  for (int i = 0; i < number_of_hr_lines; i++) {
    write(*f, hr->hr_line, ft_strlen(hr->hr_line));
  }
  write(*f, hr->hr_done, ft_strlen(hr->hr_done));
  write(*f, '\n', 1);
}

void rw(const Header *hr, int *f, struct *t, char *s) {
  if (hr == NULL || f == -1) return;

  size_t total_spaces = 71;
  size_t left_padding = 3;
  size_t left_columns = 9;
  size_t right_column = total_spaces - left_padding - ft_strlen(t->info);

  write(*f, hr->hr_open, ft_strlen(hr->hr_open));
  write(*f, t->name, ft_strlen(t->name));
  write(*f, t->info, ft_strlen(t->info));

}
