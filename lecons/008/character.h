#ifndef CHARACTER_H
#define CHARACTER_H

#include <stddef.h>

typedef struct {
  char *name;
  int level;
  int score;
  int hp;
  int mp;
} Character;

Character *p_create(const char *name);
void p_state(const Character *p);
void p_wreck(Character **p);

#endif
