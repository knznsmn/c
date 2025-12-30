/*****************************************************************************/
/*   001/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/30 19:10:56                                            */
/*   Updated: 2025/12/30 19:10:56                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

enum {
  SIZE = 64
};

typedef struct {
  char *name;
  int level;
  int hp;
} Character;

Character character_create(const char *name, int level, int hp);
void character_print(const Character *c);
void character_destroy(Character *c);

int main(void) {

  
  return 0;
}

Character character_create(const char *name, int level, int hp) {

}

void character_print(const Character *c) {
  
}

void character_destroy(Character *c) {

}


