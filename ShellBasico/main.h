#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> /* stat */
#include <sys/stat.h>  /* stat */

void execmd(char **argv);
char *get_location(char *command);

/* Compilar: gcc -Wall -Wextra -Werror -pedantic main.c -o eshell */
/* gcc -Wall -Wextra -Werror -pedantic main.c execmd.c  -o eshell */
/* Ctrl+Shift+C */
/* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o eshell */

/* OBJETIVO: USAR FORK */