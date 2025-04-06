#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../functions/strings.c"

void header(FILE *f, char **argv);

#define BUFFER_SIZE 32

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("\nUsage: %s <project name>\n\n", argv[0]);
  }

  // Starts sorting out the argv's
  else {
    char cmd[BUFFER_SIZE];
    char dir[BUFFER_SIZE];
    char fil[BUFFER_SIZE];

    // Check if the argument is a C file
    int length = ft_strlen(argv[1]);
    if (argc == 2 && ((argv[1][length - 1] == 'c') && (argv[1][length - 2] == '.'))) {
      ft_strcpy(fil, argv[1]);
    }

    // If not,
    else if (argc == 2) {
      ft_strcpy(dir, argv[1]);
    }

    // Else if arguments are more than 2,
    else {
      // Traverse through all the arguments
      for (int i = 0; i < argc; i++) {
        length = ft_strlen(argv[i]);
        int j = 0;
        if (ft_stravz(argv[i], '.')) {
          printf("%s is a file.\n", argv[i]);
        }
        else {
          printf("%s is a directory.\n", argv[i]);
        }
      }
    }




    // sprintf(cmd, "mkdir %s\n", argv[1]);
    // system(cmd);
    // printf("The directory \"%s\" was created successfully.\n", argv[1]);

    // sprintf(cmd, "touch %s/main.c\n", argv[1]);
    // system(cmd);
    // printf("The main.c file was created successfully.\n");

    // int i = 0;
    // while (argv[1][i] != '\0') {
    //   cmd[i] = argv[1][i];
    //   i++;
    // }
    // cmd[i] = '\0';


  }
}

void header(FILE *f, char **argv) {
  
}
