/*****************************************************************************/
/*   001/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2025/12/31 11:23:11                                            */
/*   Updated: 2025/12/31 14:04:44                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int level;
} Player;

void ft_free(char *s);
size_t ft_strlen(const char *s);
int ft_strcp(char *s1, const char *s2);
Player *player_create(const char *name);
void player_destroy(Player *p);

int main(void) {
  char *name = "Hrafnkell";
  Player *hrafnkell = player_create(name);

  if (hrafnkell == NULL) {
    return 1;
  }
  
  printf("Player %s(lv%d) created.\n", hrafnkell->name, hrafnkell->level);
  player_destroy(hrafnkell);

  return 0;
}

size_t ft_strlen(const char *s) {
  size_t i = 0;
  for (i = 0; *(s + i) != '\0'; i++) {
  }
  return i;
}

int ft_strcp(char *s1, const char *s2) {
  if (s1 == NULL || s2 == NULL) {
    return 1;
  }
  int i = 0;
  for (i = 0; *(s2 + i) != '\0'; i++) {
    *(s1 + i) = *(s2 + i);
  }
  *(s1 + i) = '\0';

  return 0;
}

Player *player_create(const char *name) {
  Player *player = malloc(sizeof *player);
  if (player == NULL) {
    return NULL;
  }
  player->name = malloc(ft_strlen(name) + 1);
  if (player->name == NULL) {
    free(player);
    return NULL;
  }
  ft_strcp(player->name, name);
  player->level = 1;

  return player;
}

void player_destroy(Player *p) {
  if (p == NULL) {
    return;
  }
  free(p->name);
  free(p);
}
