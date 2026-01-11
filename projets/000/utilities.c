/*****************************************************************************/
/*   utilities.c                                                             */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/10 07:03:12                                            */
/*   Updated: 2026/01/10 07:03:12                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

enum { 
  BUFFER_SIZE = 4096,
  EOF = -1,
  NEWLINE = 10
};

void ft_putchar(const char c) {

  write(1, &c, 1);
}

size_t ft_strlen(const char *s) {
  if (!s) return 0;

  size_t i = 0;
  while (s[i] != '\0') {
    i++;
  }

  return i;
}

void ft_puts(const char *s) {
  if (s == NULL) return;
  
  size_t i = 0;
  while (i < ft_strlen(s)) {
    ft_putchar(s[i]);
    i++;
  }
  ft_putchar('\n');
}

void ft_print(const char *s) {
  if (s == NULL) return;

  size_t i = 0;
  while ( i <= ft_strlen(s)) {
    ft_putchar(s[i]);
    i++;
  }
}
void ft_fputs(int f, char *s) {
  if (!f || s == NULL) return;

  write(f, s, ft_strlen(s));
  write(f, "\n", 1);
}

void itoa(char s[], size_t n) {

  char integers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char ch[BUFFER_SIZE];
  size_t digit = 10;
  size_t i, j;
  i = j = 0;
  while (n > digit) {
    ch[i] = integers[n % 10];
    n /= digit;
    i++;
  }
  ch[i] = integers[n];
  ch[++i] = '\0';
  --i;
  while (i > 0) {
    s[j] = ch[i];
    j++;
    i--;
  }
  s[j++] = ch[i--];
  s[j++] = '\0';
}

char ft_getchar() {
  int c;
  read(1, &c, 1);

  return c;
}

void ft_gets(char *s) {
  int i = 0;
  while((s[i] = ft_getchar()) != EOF) {
    i++;
  }
  s[i] = '\0';
}

void ft_getline(char *s) {
  int i = 0;
  while((s[i] = ft_getchar()) != '\n') {
    i++;
  }
  s[i] = '\0';
}

char ft_fgetchar(int f) {
  int c;
  read(f, &c, 1);

  return c;
}

void ft_fgets(int *f, char *s) {
  int i = 0;
  while ((s[i] = ft_fgetchar(*f)) != EOF) {
    i++;
  }
  s[i] = '\0';
}
