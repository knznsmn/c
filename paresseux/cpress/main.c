#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("\nUsage: %s <project name>\n\n", argv[0]);
  }
  else {
    char cmd[BUFFER_SIZE];
    char dir[BUFFER_SIZE];
    char 
    sprintf(cmd, "mkdir %s\n", argv[1]);
    system(cmd);
    printf("The directory \"%s\" was created successfully.\n", argv[1]);

    sprintf(cmd, "touch %s/main.c\n", argv[1]);
    system(cmd);
    printf("The main.c file was created successfully.\n");

    int i = 0;
    while (argv[1][i] != '\0') {
      cmd[i] = argv[1][i];
      i++;
    }
    cmd[i] = '\0';
  }
}
