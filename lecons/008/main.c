/*****************************************************************************/
/*   008/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/01 13:07:04                                            */
/*   Updated: 2026/01/01 13:29:08                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include "character.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("\nUsage: %s <string>\n\n", argv[0]);
  }
  else {
    Character *player = p_create(*(argv + 1));
    if (!player) return 1;
    p_state(player);
  
    Character *player_2 = p_clone(player); 
    if (!player_2) return 1;

    p_wreck(&player);
    player.name = "NiceGame";
    p_state(player_2);

    p_wreck(&player_2);
  }

  return 0;
}
