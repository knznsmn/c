#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "character.h"

struct Character {
  char *name;
  int level;
  int score;
  int hp;
  int mp;
};

static void character_init(Character *c) {
  c->level = 1;
  c->score = 0;
  c->hp    = 100;
  c->mp    = 100;
}

static int character_is_valid(const Character *c) {
  if (!c) return 0;

  if (!c->name) return 0;
  if (c->level < 1) return 0;
  if (c->score < 0) return 0;
  if (c->hp < 0) return 0;
  if (c->mp < 0) return 0;

  return 1;
}
Character *character_create(const char *name) {
  if (!name) return NULL;

  Character *c = malloc(sizeof *c);
  if (!c) return NULL;

  c->name = malloc(strlen(name) + 1);
  if (!c->name) {
    free(c);
    return NULL;
  }

  strcpy(c->name, name);
  character_init(c);
  return c;
}

Character *character_clone(const Character *src) {
  if (!character_is_valid(src)) return NULL;

  Character *c = character_create(src->name);
  if (!c) return  NULL;

  c->level = src->level;
  c->score = src->score;
  c->hp    = src->hp;
  c->mp    = src->mp;

  return c;
}
void character_info(const Character *c) {

  if (!character_is_valid(c)) {
    printf("Invalid character!\n");
    return;
  }
  printf("\nCharacter: %s (lv%d)\n", c->name, c->level);
  printf("  Score: %d\n", c->score);
  printf("  HP: %d\n", c->hp);
  printf("  MP: %d\n\n", c->mp);
}
void character_wreck(Character **c) {
  if (!c || !*c) return;

  free((*c)->name);
  free(*c);
  *c = NULL;
}
const char *character_name(const Character *c) {
  if (!character_is_valid(c)) return NULL;

  return c->name;
}
int character_level(const Character *c) {
  if (!character_is_valid(c)) return 0;

  return c->level;
}

int character_score (const Character *c) {
  if (!character_is_valid(c)) return 0;

  return c->score;
}
