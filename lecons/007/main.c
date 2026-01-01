/*****************************************************************************/
/*   007/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/29 17:24:46                                            */
/*   Updated: 2026/01/01 13:05:39                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s);
void ft_strcp(char *dst, const char *src);

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

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("\nUsage: %s <string>\n\n", argv[0]);
  }
  else {
    Character *player = p_create(*(argv + 1));
    if (player == NULL) {
      return 1;
    }

    p_state(player);
    p_wreck(&player);
  }

  return 0;
}

size_t ft_strlen(const char *s) {
  size_t i = 0;
  while (*(s + i) != '\0') {
    i++;
  }
  return i;
}
void ft_strcp(char *dst, const char *src) {
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
