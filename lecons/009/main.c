/*****************************************************************************/
/*   009/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/12 11:14:22                                            */
/*   Updated: 2026/01/12 11:14:22                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "character.h"

#define BUFFER_SIZE 64

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("\n\nUsage: %s <Player name>\n\n", argv[0]);
    return 1;
  }
  else {
    size_t len = strlen(argv[1]);
    if (len > BUFFER_SIZE) {
      printf("%s has %zu characters.\n", argv[1], len);
      printf("Limit your name to a maximum of %d letters\n", BUFFER_SIZE - 1);
      return 1;
    }
    Character *player = character_create(argv[1]);
    if (!player) return 1;
    Character *enemy = character_clone(player);

    printf("Player name: %s.\n", character_name(player));
    printf("  level: %d.\n", character_level(player));
    printf("  score: %d.\n", character_score(player));
    putchar('\n');
    printf("Player name: %s.\n", character_name(enemy));
    printf("  level: %d.\n", character_level(enemy));
    printf("  score: %d.\n", character_score(enemy));

    character_info(player);
    character_info(enemy);
    character_wreck(&player);
    character_wreck(&enemy);

    return 0;
  }
}
