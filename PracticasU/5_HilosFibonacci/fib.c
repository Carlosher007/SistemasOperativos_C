/**
 * Este programa calcula sobre cada uno de los enteros de un vector su
 * fibonacci.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h> //uso de hilos
#define max_random(min, max) min + rand() % (max + 1 - min)
#define printf_vector(v, n) \
  for (i = 0; i < n; i++)   \
  {                         \
    printf("%d ", v[i]);    \
  }
#define println printf("\n")
#define CONSTANTE 5

int fibonacci(int);
int main(int argc, char *argv[])
{
  int vl, // vl: vector_length
      mr; // mr: max_random
  int *vector;
  int i;
  if (argc != 3)
  {
    printf("Ejecutar de la siguiente manera: \n");
    printf("\t %s <vector_length> <max_random>\n", argv[0]);
    exit(1);
  }
  vl = atoi(argv[1]);
  mr = atoi(argv[2]);

  vector = (int *)malloc(sizeof(int) * vl);

  srand(time(NULL));
  for (i = 0; i < vl; i++)
  {
    vector[i] = max_random(mr - CONSTANTE, mr);
  }
  printf_vector(vector, vl);
  println;

  for (i = 0; i < vl; i++)
  {
    vector[i] = fibonacci(vector[i]);
  }
  // printf("%d\n",fibonacci(vl));

  printf_vector(vector, vl);
  println;

  return 0;
}

int fibonacci(int m)
{
  if (m == 0)
    return 0;
  if (m == 1)
    return 1;
  return fibonacci(m - 1) + fibonacci(m - 2);
}

/* // El codigo anterior usa un solo nucleo,
para usar varios nucleos se debe usar hilos,
para ello se debe usar la libreria pthread.h

// Ya con la libreria para usar hilos se debe
crear una estructura para pasarle los parametros
a la funcion que se ejecutara en el hilo

// La estructura debe tener los parametros que se
necesiten para la funcion que se ejecutara en el
hilo

// La estructura debe tener un puntero a la
funcion que se ejecutara en el hilo

// La estructura debe tener un puntero a la
variable que se usara para guardar el resultado
de la funcion que se ejecutara en el hilo

//la nueva funcion main que implementa los hilos
(2 nucleos) es:
*/
