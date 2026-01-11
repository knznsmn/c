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
Character *p_clone(const Character *src) {
  if (!src || !src->name) return NULL;

  Character *copy = malloc(sizeof *copy);
  if (!copy) return NULL;

  copy->name = malloc(ft_strlen(src->name) + 1);
  if (!copy->name) {
    free(copy);
    return NULL;
  }
  ft_strcp(copy->name, src->name);

  copy->level = src->level;
  copy->score = src->score;
  copy->hp    = src->hp;
  copy->mp    = src->mp;

  return copy;
}

void p_state(const Character *p) {
  if (!p) return;

  printf("\n\nCharacter: %s\n", p->name);
  printf("Level:\t%d\n", p->level);
  printf("Score:\t%d\n", p->score);
  printf("HP:\t%d\n", p->hp);
  printf("MP:\t%d\n\n", p->mp);
}

void p_wreck(Character **p) {
  if (!p || !*p) return;

  free((*p)->name);
  free(*p);
  *p = NULL;
}


