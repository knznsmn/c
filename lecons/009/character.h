#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct Character Character;

Character *character_create(const char *name);
Character *character_clone(const Character *src);
void character_info(const Character *c);
void character_wreck(Character **c);
const char *character_name(const Character *c);
int character_level(const Character *c);
int character_score (const Character *c);

#endif
