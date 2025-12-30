/*****************************************************************************/
/*   007/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/29 17:24:46                                            */
/*   Updated: 2025/12/29 17:24:46                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>   /* printf, fprintf */
#include <stdlib.h>  /* exit codes, NULL */
#include "character.h" /* Character API: create, print, destroy */

int main(void) {
  /* Create a Character on the heap.
   * We pass a string literal for the name; the create function copies it.
   * The returned pointer `c` must be freed with `character_destroy`.
   */
  Character *c = character_create("Hrafnkell", 5, 42);

  /* Always check for allocation failure. Many beginners forget this and
   * encounter crashes when memory is exhausted.
   */
  if (!c) {
    fprintf(stderr, "Failed to create character\n");
    return 1;
  }

  /* Use the character: printing its fields. The function accepts a
   * `const Character *` since it does not modify the object.
   */
  character_print(c);

  /* When finished, free all memory owned by the character. After this call
   * `c` becomes invalid; in larger programs it's common to set `c = NULL`.
   */
  character_destroy(c);

  return 0; /* success */
}
