/*
Proceso => Programa en ejecución
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  // Fork => Clonar un proceso.
  // fork() => Devuelve el PID del proceso hijo si es el padre
  // fork() => Devuelve 0 si es el proceso hijo.
  // fork() => Devuelve -1 si hay error.

  int variable = 1;
  int result = fork();
  // La razon por la que imprime tanto el if, como el else, es pq tanto se clono el proceso, entonces existe un proceso padre y un proceso hijo.
  if (result != 0)
  {
    printf("Soy el proceso padre, mi variable es %i\n",variable);
    variable=10;
  }
  else
  {
    printf("Soy el proceso hijo, mi variable es %i\n", variable);
    variable=30;
  }

  printf("La variable finalmente es %i\n", variable);
}