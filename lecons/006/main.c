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
  
  int *characters;

  init_array(characters, 6);
  if (characters == NULL) {
    return 1;
  }
  print_array(characters, 6);
  printf("%p\n", characters);

  free(characters);
  characters = NULL;

  return 0;
}

void init_array(int *arr, size_t len) {
  arr = malloc((sizeof *arr) * len);
  for (size_t i = 0; i < len; i++) {
    *(arr + i) = i + 2;
  }
  for (size_t i = 0; i < len; i++) {
    printf("%d", *(arr + i));
    if (i == (len - 1)) {
      printf(".\n");
    }
    else {
      printf(", ");
    }
  }
  printf("Array successfully allocated.\n");
}

void print_array(const int *arr, size_t len) {
  printf("%p\n", arr);
  for (size_t i = 0; i < len; i++) {
    printf("%d\n", *(arr + i));
  }
}
