/* character.c
 * Implementation for Character create/print/destroy
 *
 * This file provides three functions:
 *  - character_create: allocate and initialize a Character on the heap
 *  - character_print:  print a Character's fields in a human-readable way
 *  - character_destroy: free all heap memory owned by a Character
 */

#include "character.h"   /* local header: declaration of Character and functions */
#include <stdio.h>        /* for printf, puts, fprintf */
#include <string.h>       /* for strlen and memcpy */

/*
 * Allocate and initialize a Character.
 * Parameters:
 *  - name: C-string (NUL-terminated) to copy into the new Character (must not be NULL)
 *  - level: integer level value to store
 *  - hp: integer hit-points value to store
 * Returns:
 *  - pointer to a heap-allocated Character on success
 *  - NULL on error (e.g., allocation failure or NULL input)
 */
Character *character_create(const char *name, int level, int hp) {
    /* Defensive check: if caller passed NULL for name, we cannot proceed */
    if (!name) return NULL;

    /* Allocate memory for the Character struct itself.
     * Using `sizeof *c` is a common idiom: it matches the size of the
     * object pointed to by `c` and avoids repeating the type name.
     */
    Character *c = malloc(sizeof *c);
    /* Check allocation success: malloc returns NULL on failure */
    if (!c) return NULL;

    /* Determine how many bytes we need to copy from the provided name.
     * `strlen(name)` returns the number of characters before the terminating
     * NUL ('\0'), but it does not count the NUL itself. We add 1 so the
     * allocated buffer can hold all characters plus the terminating NUL.
     */
    size_t len = strlen(name) + 1;

    /* Allocate a buffer for the name on the heap. We allocate `len` bytes,
     * which includes space for the terminating NUL.
     */
    c->name = malloc(len);
    /* If the name allocation fails, free the previously allocated struct to
     * avoid a memory leak, then return NULL to indicate failure.
     */
    if (!c->name) {
        free(c);
        return NULL;
    }

    /* Copy the bytes from the source name into our newly allocated buffer.
     * We use memcpy with `len` so the terminating NUL is copied as well;
     * this leaves `c->name` as a valid NUL-terminated C string.
     */
    memcpy(c->name, name, len);

    /* Store the remaining fields. These are ordinary integer assignments. */
    c->level = level;
    c->hp = hp;

    /* Return the pointer to the fully initialized Character. Caller owns it. */
    return c;
}


/* Print the fields of a Character in a readable format. This function does
 * not modify the Character and therefore takes a pointer to const.
 */
void character_print(const Character *c) {
    /* Defensive check: if caller passed NULL, print a helpful message and
     * return. Many C APIs choose to silently do nothing; here we print so the
     * beginner can see something helpful during debugging.
     */
    if (!c) {
        puts("(null character)");
        return;
    }

    /* Print the name, level and hp. The `?:` expression `c->name ? c->name :
     * "(no name)"` ensures that if the `name` field for some reason is NULL
     * we don't pass NULL to printf (which would be undefined behavior for
     * the %s format). Instead we print a placeholder string.
     */
    printf("Name: %s\nLevel: %d\nHP: %d\n",
           c->name ? c->name : "(no name)",
           c->level,
           c->hp);
}


/* Free all heap memory owned by the Character.
 * The function accepts a non-const pointer because it frees the object.
 */
void character_destroy(Character *c) {
    /* If caller passes NULL, do nothing. This makes the function safe to
     * call unconditionally (e.g., `character_destroy(ptr); ptr = NULL;`).
     */
    if (!c) return;

    /* Free the heap-allocated name buffer first, then free the struct.
     * The order matters only insofar as we should not access `c->name`
     * after `free(c)`; freeing the name first keeps semantics clear.
     */
    free(c->name);
    free(c);
}

