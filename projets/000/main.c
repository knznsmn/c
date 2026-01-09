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

void newline(int *f);
void padding(int *f, const int n);
void row_line(const Header *hr, int *f);
void row_void(const Header *hr, int *f);
void row_info(const Header *hr, char *s, int *f);
void row_mois(const Header *hr, Detail *t, int *f);
void row_file(const Header *hr, const Filename *fl, int *f);

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
    

    Filename file;
    file.name = extract_fil(argv[1]);
    file.exts = extract_ext(argv[1]);
    file.name_size = ft_strlen(file.name);
    file.exts_size = ft_strlen(file.exts);
    
    Header *header = create_hr(file.exts);
    
    Detail name;
    name.name = "By:";
    name.info = "knznsmn";
    name.name_size = ft_strlen(name.name);
    name.info_size = ft_strlen(name.info);

    Detail mail;
    mail.name = "Email:";
    mail.info = "mail@jccesar.com";
    mail.name_size = ft_strlen(mail.name);
    mail.info_size = ft_strlen(mail.info);

    char *info = "Codes for days.";

    row_line(header, &fd);
    row_file(header, &file, &fd);
    row_void(header, &fd);
    row_mois(header, &name, &fd);
    row_mois(header, &mail, &fd);
    row_void(header, &fd);
    row_info(header, info, &fd);
    row_line(header, &fd);
    newline(&fd);
    
    free(file.name);
    free(file.exts);
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

  int borders_size = hr->hr_open_size + hr->hr_done_size;
  int number_of_hr_lines = HEADER_WIDTH - borders_size;

  write(*f, hr->hr_open, hr->hr_open_size);
  for (int i = 0; i < number_of_hr_lines; i++) {
    write(*f, hr->hr_line, hr->hr_line_size);
  }
  write(*f, hr->hr_done, hr->hr_done_size);
  newline(f);
}
void row_file(const Header *hr, const Filename *fl, int *f) {
  if (hr == NULL || fl == NULL) return;

  char slash = '/';
  size_t border_left_size = ft_strlen(hr->hr_open);
  size_t border_righ_size = ft_strlen(hr->hr_done);
  size_t border_size = border_left_size + border_righ_size;
  size_t total_space = HEADER_WIDTH - border_size;
  size_t left_column = LEFT_PADDING + fl->name_size + 1 + fl->exts_size;
  size_t r_col_copad = total_space - left_column;

  write(*f, hr->hr_open, ft_strlen(hr->hr_open));
  padding(f, LEFT_PADDING);
  write(*f, fl->name, fl->name_size);
  write(*f, &slash, 1);
  write(*f, fl->exts, fl->exts_size);
  padding(f, r_col_copad);
  write(*f, hr->hr_done, ft_strlen(hr->hr_done));
  newline(f);
}

void row_mois(const Header *hr, Detail *t, int *f) {
  if (hr == NULL || f == NULL) return;

  size_t borders_size = hr->hr_open_size + hr->hr_done_size;
  size_t total_spaces = HEADER_WIDTH - borders_size;

  size_t left_content = 9;
  size_t left_columns = left_content + LEFT_PADDING;
  size_t left_col_pad = left_content - t->name_size;
  size_t right_column = total_spaces - left_columns;
  size_t right_col_pd = right_column - t->info_size;

  write(*f, hr->hr_open, hr->hr_open_size);
  padding(f, LEFT_PADDING);
  write(*f, t->name, t->name_size);
  padding(f, left_col_pad);
  write(*f, t->info, t->info_size);
  padding(f, right_col_pd);
  write(*f, hr->hr_done, hr->hr_done_size);
  newline(f);
}

void row_void(const Header *hr, int *f) {

  size_t borders_size = hr->hr_open_size + hr->hr_done_size;
  size_t total_spaces = HEADER_WIDTH - borders_size;
  
  write(*f, hr->hr_open, hr->hr_open_size);
  padding(f, total_spaces);
  write(*f, hr->hr_done, hr->hr_done_size);
  newline(f);
}

void row_info(const Header *hr, char *s, int *f) {

  size_t s_size = ft_strlen(s);
  size_t borders_size = hr->hr_open_size + hr->hr_done_size;
  size_t total_spaces = HEADER_WIDTH - borders_size;
  size_t left_content = LEFT_PADDING + s_size;
  size_t right_col_pd = total_spaces - left_content;

  write(*f, hr->hr_open, hr->hr_open_size);
  padding(f, LEFT_PADDING);
  write(*f, s, s_size);
  padding(f, right_col_pd);
  write(*f, hr->hr_done, hr->hr_done_size);
  newline(f);
}
