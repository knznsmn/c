#include <stdio.h>
#include <stdlib.h>
#include "character.h"

static size_t ft_strlen(const char *s) {
  size_t i = 0;
  while (*(s + i) != '\0') {
    i++;
  }
  return i;
}
static void ft_strcp(char *dst, const char *src) {
  size_t i = 0;
  while (*(src + i) != '\0') {
    *(dst + i) = *(src + i);
    i++;
  }
  *(dst + i) = '\0';
}

Character *p_create(const char *name) {
  if (name == NULL) {
    return NULL;
  }
  Character *p = malloc(sizeof *p);
  if (p == NULL) {
    return NULL;
  }

  p->name = malloc(ft_strlen(name) + 1);
  if (p->name == NULL) {
    free(p);
    return NULL;
  }

  ft_strcp(p->name, name);
  p->level = 1;
  p->score = 0;
  p->hp    = 100 + (p->level * p->score);
  p->mp    = 100 + (p->level * p->score);

  return p;
}

void p_state(const Character *p) {
  printf("\n\nCharacter: %s\n", p->name);
  printf("Level:\t%d\n", p->level);
  printf("Score:\t%d\n", p->score);
  printf("HP:\t%d\n", p->hp);
  printf("MP:\t%d\n\n", p->mp);
}

void p_wreck(Character **p) {
  if (p == NULL) {
    return;
  }

  free((*p)->name);
  free(*p);
  *p = NULL;
}


