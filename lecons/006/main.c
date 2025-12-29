/*****************************************************************************/
/*   006/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@knznsmn.com                                               */
/*   Created: 2025/12/29 02:47:02                                            */
/*   Updated: 2025/12/29 02:47:02                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void init_array(int *arr, size_t len);
void print_array(const int *arr, size_t len);

int main(void) {
  
  int *values = malloc(sizeof *values * 6);
  if (values == NULL) {
    return 1;
  }
  init_array(values, 6);
  print_array(values, 6);

  free(values);
  values = NULL;

  return 0;
}

void init_array(int *arr, size_t len) {
  for (size_t i = 0; i < len; i++) {
    *(arr + i) = i + 2;
  }
}

void print_array(const int *arr, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d\n", *(arr + i));
  }
}
