/*****************************************************************************/
/*   001/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/05 12:31:31                                            */
/*   Updated: 2026/01/05 12:31:31                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

typedef struct {
  char *hr_c_open;
  char *hr_c_close;
  char *hr_c_line;
  int hr_width;
} Header;

void initiate(Header *e);
void hr_delete(Header **e);
void hr_prints(Header *s);

void extract_ext(char *e, const char *s);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("\n\nUsage: %s <filename>\n\n", argv[0]);
    return 0;
  }
  Header *hr = malloc(sizeof *hr);
  initiate(hr);
  char extension[SIZE];
  extract_ext(extension, argv[1]);

  printf("Extension is '%s'.\n", extension);
  hr_prints(hr);
  hr_prints(hr);

  hr_delete(&hr);
  return 0;
}

void extract_ext(char *e, const char *s) {
  if (s == NULL) return;
  
  // Find the last dot
  size_t length = strlen(s);
  size_t i = length;
  while (s[i] != '.') {
    i--;
  }
  length = i;
  i = 0;
  while (s[length] != '\0') {
    e[i] = s[length];
    length++;
    i++;
  }
  e[i] = '\0';
}

void initiate(Header *e) {
  if (e == NULL) return;

  char *ascii[] = {"/*", "*/", "*"};
  
  e->hr_c_open   = malloc(sizeof strlen(ascii[0]) + 1);
  if (e->hr_c_open == NULL) {
    free(e->hr_c_open);
    return;
  }
  e->hr_c_close  = malloc(sizeof strlen(ascii[1]) + 1);
  if (e->hr_c_close == NULL) {
    free(e->hr_c_close);
    return;
  }
  e->hr_c_line   = malloc(sizeof strlen(ascii[2]) + 1);
  if (e->hr_c_line == NULL) {
    free(e->hr_c_line);
    return;
  }
  strcpy(e->hr_c_open, ascii[0]);
  strcpy(e->hr_c_close, ascii[1]);
  strcpy(e->hr_c_line, ascii[2]);
  e->hr_width    = 75;
}

void hr_delete(Header **e) {
  if (e == NULL) return;
  
  free((*e)->hr_c_open);
  free((*e)->hr_c_close);
  free((*e)->hr_c_line);
  free(*e);
  *e = NULL;
}

void hr_prints(Header *s) {
  printf("%s", s->hr_c_open);
  for (int i = 0; i < s->hr_width; i++) {
    printf("%s", s->hr_c_line);
  }
  printf("%s\n", s->hr_c_close);
}


