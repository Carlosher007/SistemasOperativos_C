#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char c[2][8] = {"Hola", "Mensaje"};
  printf("%s\n", c[0]);
  printf("%s\n", c[1]);

  // Declarar eso dentro del hip no la cola
  char **string = malloc(sizeof(char*) * 2);

  char *msg1 = malloc(sizeof(char)* 8);
  char *msg2 = malloc(sizeof(char)* 8);

  //el strcpy sirve para copiar un string a otro
  strcpy(msg1,"Hello");
  strcpy(msg2,"Mensaje");

  string[0] = msg1;
  string[1] = msg2;

  printf("%s\n", string[0]);
  printf("%s\n", string[1]);
}