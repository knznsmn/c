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

typedef struct {
  char *name;
  char *info;
} Detail;

enum {
  HEADER_WIDTH = 80
};

void padding(int *f, const int n);
void newline(int *f);
void row_line(const Header *hr, int *f);
void row_mois(const Header *hr, int *f, Detail *t);

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
    name.name = "By:";
    name.info = "knznsmn";
    mail.name = "Email:";
    mail.info = "mail@jccesar.com";

void newline(int *f);
    row_line(header, &fd);
    row_mois(header, &fd, &name);
    row_mois(header, &fd, &mail);
    row_line(header, &fd);

    destroy_hr(&header);
    close(fd);
  }
  return 0;
}

void padding(int *f, const int n) {
  char space = ' ';
  for (int i = 0; i < n; i++) {
    write(*f, &space, 1);
  }
}

void newline(int *f) {
  char c = '\n';
  write(*f, &c, 1);
}

void row_line(const Header *hr, int *f) {
  if (hr == NULL || f == NULL) return;

  int number_of_hr_lines = 80;
  if (ft_strcmp(hr->hr_extf, ".lua")) {
    number_of_hr_lines = 78;
  }
  else if (ft_strcmp(hr->hr_extf, ".html")) {
    number_of_hr_lines = 77;
  }

  write(*f, hr->hr_open, ft_strlen(hr->hr_open));
  for (int i = 0; i < number_of_hr_lines; i++) {
    write(*f, hr->hr_line, ft_strlen(hr->hr_line));
  }
  write(*f, hr->hr_done, ft_strlen(hr->hr_done));
  newline(f);
}
void row_date(const Header *hr, const char *s) {
  const char *ext = extract_ext(s);

}

void row_mois(const Header *hr, int *f, Detail *t) {
  if (hr == NULL || f == NULL) return;

  size_t border_left_size = ft_strlen(hr->hr_open);
  size_t border_righ_size = ft_strlen(hr->hr_done);
  size_t borders_size = border_left_size + border_righ_size;
  size_t total_spaces = HEADER_WIDTH - borders_size;

  size_t left_padding = 3;
  size_t left_columns = 9;
  size_t left_col_pad = left_columns - ft_strlen(t->name);
  size_t right_column = total_spaces - left_columns;
  size_t right_col_pd = right_column - ft_strlen(t->info);

  write(*f, hr->hr_open, ft_strlen(hr->hr_open));
  padding(f, left_padding);
  write(*f, t->name, ft_strlen(t->name));
  padding(f, left_col_pad);
  write(*f, t->info, ft_strlen(t->info));
  padding(f, right_col_pd);
  write(*f, hr->hr_done, ft_strlen(hr->hr_done));
  newline(f);
}
