/*****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/14 10:12:04                                            */
/*   Updated: 2026/01/14 10:12:04                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct IntArray {
  int max;
  int len;
  int num[];
};

void ints_init(struct IntArray *n);
void ints_prnt(struct IntArray *n);

int main(int argc, char **argv) {
  struct IntArray ints;
  if (argc < 2) {
    printf("This program inserts an item into an array of `int`s.\n");
    printf("Enter the length of the array: ");
    scanf("%d", &ints.len);
    printf("\nEnter the max integer to store: ");
    scanf("%d", &ints.max);
    putchar('\n');
  }
  else {
    for (int i = 0; i < argc; i++) {
      ints.num[i] = atoi(argv[i + 1]);
    }
  }

  ints_init(&ints);
  ints_prnt(&ints);

  return 0;
}

void ints_init(struct IntArray *n) {
  if (!n) return;

  for (int i = 0; i < n->len; i++) {
    printf("Enter an integer to add (%d/%d): ", n->len - i, n->len);
    scanf("%d", &n->num[i]);
    putchar('\n');
  }
}

void ints_prnt(struct IntArray *n) {
  if (!n) return;
  printf("These are the array's contents:\n");
  for (int i = 0; i < n->len; i++) {
    printf("  %3d\n", n->num[i]);
  }
}
