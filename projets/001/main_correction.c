#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int level;
} Player;

size_t ft_strlen(const char *s);
void ft_strcp(char *dst, const char *src);
Player *player_create(const char *name);
void player_destroy(Player *p);

int main(void) {
    const char *name = "Hrafnkell";
    Player *hrafnkell = player_create(name);

    if (hrafnkell == NULL) {
        return 1;
    }

    printf("Player %s(lv%d) created.\n",
           hrafnkell->name, hrafnkell->level);

    player_destroy(hrafnkell);
    return 0;
}

size_t ft_strlen(const char *s) {
    size_t i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void ft_strcp(char *dst, const char *src) {
    size_t i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
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

