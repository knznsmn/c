# C Programming Language - AI Coding Instructions

## Project Overview
This is a learning repository for C programming language fundamentals. Reference material is in `aide/` directory (K&R "The C Programming Language" book).

## Code Organization
- Source files should be created at root level or in topical subdirectories
- Keep examples self-contained with clear filenames (e.g., `pointers_example.c`, `linked_list.c`)
- Related exercises from book chapters can be grouped in chapter-specific folders

## Build & Run Conventions
- **Compiler**: Use `gcc` or `clang` with warnings enabled
- **Compilation**: `gcc -Wall -Wextra -std=c11 -o program source.c`
- **Binary naming**: Avoid generic names like `a.out` or `main` (already in `.gitignore`)
- Use descriptive output names: `gcc -o string_ops string_ops.c`

## Code Style Guidelines
- Follow K&R style conventions from the reference book
- Use clear, descriptive variable names
- Add comments explaining non-obvious logic and algorithms
- Keep functions focused and single-purpose
- Include usage examples in comments or separate main() for testing

## File Structure for Examples
```c
/* Brief description of what this demonstrates */
#include <stdio.h>
#include <stdlib.h>

// Function declarations

// Main demonstration
int main(void) {
    // Example usage
    return 0;
}

// Function implementations with explanations
```

## When Creating New Code
1. Add header comments explaining the concept being demonstrated
2. Include compilation instructions as a comment at the top
3. Demonstrate both correct usage and common pitfalls where relevant
4. For data structures, show allocation, usage, and cleanup
5. Test with edge cases (NULL pointers, empty inputs, boundary conditions)

## Memory Management
- Always pair `malloc()`/`calloc()` with `free()`
- Check return values of memory allocation functions
- Initialize pointers to NULL when declared
- Comment ownership and lifetime of dynamically allocated memory

## Common Patterns in This Repository
- Educational code over production patterns
- Emphasize clarity and learning over optimization
- Include step-by-step comments for complex algorithms
- Show evolution of concepts (basic → advanced implementations)

## Reference Material
See `aide/the-c-programming-language.pdf` for authoritative guidance on C language features and idioms.
