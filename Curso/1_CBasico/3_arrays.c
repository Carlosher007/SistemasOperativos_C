#include <stdio.h>
#include <stdlib.h>

int main()
{
  // int array[] = {1, 2, 3, 4, 5};
  // Es mejor declararlos de esta forma por problemas de limitación : malloc (zona de memoria con cierto bites
  int *array = malloc(sizeof(int) * 8); //se almacenan en el beat no en el stack
  // La memoria dinámica que se almacena en el heap es aquella que se utiliza para almacenar datos que se crean en el medio de la ejecución de un programa.

  for (int i = 0; i < 8; i++)
  {
    array[i] = i + 1;
  }

  for (int i = 0; i < 8; i++)
  {
    printf("Valor de array[%i]: %i\n", i, array[i]);
  }

  //Liberamos la zona de memoria
  free(array);
} 