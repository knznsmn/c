/* character.h
 * Public declarations for the Character type and its helper functions.
 * This header is included by users of the Character API (for example, main.c).
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdlib.h> /* for size_t and NULL (indirectly) and malloc/free usage */

/* A Character represents a simple game-style entity.
 * Fields:
 *  - name: pointer to a NUL-terminated C string stored on the heap.
 *          The Character owns this string and is responsible for freeing it.
 *  - level: integer representing character level
 *  - hp: integer representing hit points
 *
 * We write the typedef so callers can use `Character` as the type name.
 */
typedef struct Character {
    char *name; /* heap-allocated NUL-terminated string */
    int level;  /* character level */
    int hp;     /* hit points */
} Character;

/* Create a new Character on the heap.
 * - `name` must be a valid NUL-terminated string (const char*).
 * - The function makes a heap copy of `name` so the caller remains free to
 *   modify or free the original string after creation.
 * - On success returns a pointer to a heap-allocated Character which the
 *   caller must eventually free with `character_destroy()`.
 * - Returns NULL on allocation failure or if `name` is NULL.
 */
Character *character_create(const char *name, int level, int hp);

/* Print the character fields in a human-readable format. The function does
 * not modify the Character and therefore takes a pointer to const.
 */
void character_print(const Character *c);

/* Destroy a Character previously returned by `character_create`.
 * This frees both the internal `name` buffer and the Character struct itself.
 * It is safe to call with a NULL pointer.
 */
void character_destroy(Character *c);

#endif /* CHARACTER_H */
