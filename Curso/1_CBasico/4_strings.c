#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Caracter
  char c = 'a';

  // Cadena
  char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  // Forma abreviada, donde el compilador lo sustituye
  char str2[] = "Hello";
  // Con punteros
  char *p = malloc(sizeof(char) * 6);
  strcpy(p, "Hello"); // En el puntero p nos copie Hello

  // Imprimes
  printf("%s\n", p);
  
  free(p); // Liberamos la zona de memoria
}