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

// Se crea la estructura para pasar los parametros a la funcion que se ejecutara en el hilo
struct parametros
{
  int *vector; // vector es un puntero a un arreglo de enteros que sirve para almacenar los valores de fibonacci
  int *resultado; // resultado es un vector de enteros que sirve para guardar el resultado de la funcion fibonacci
  int n; // Numero de elementos del vector
  int (*funcion)(int); // Puntero a la funcion que se ejecutara en el hilo
};

// Se crea la funcion que se ejecutara en el hilo
void *funcion_hilo(void *parametros)
{
  struct parametros *p = (struct parametros *)parametros;
  int i;
  for (i = 0; i < p->n; i++)
  {
    p->resultado[i] = p->funcion(p->vector[i]);
  }
  return NULL;
}

int fibonacci(int m)
{
  if (m == 0)
    return 0;
  if (m == 1)
    return 1;
  return fibonacci(m - 1) + fibonacci(m - 2);
}

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

  // Se crean las variables para los hilos
  pthread_t hilo1, hilo2;
  // Se crean las estructuras para pasar los parametros a la funcion que se ejecutara en el hilo
  struct parametros p1, p2;
  // Se crean los vectores para guardar los resultados de la funcion que se ejecutara en el hilo
  int *resultado1, *resultado2;
  // Se asignan los valores
  p1.vector = vector;
  p1.n = vl / 2;
  p1.funcion = fibonacci;
  resultado1 = (int *)malloc(sizeof(int) * p1.n);
  p1.resultado = resultado1;

  p2.vector = vector + p1.n;
  p2.n = vl - p1.n;
  p2.funcion = fibonacci;
  resultado2 = (int *)malloc(sizeof(int) * p2.n);
  p2.resultado = resultado2;

  // Se crean los hilos
  pthread_create(&hilo1, NULL, funcion_hilo, &p1);
  pthread_create(&hilo2, NULL, funcion_hilo, &p2);

  // Se espera a que los hilos terminen
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  // Se imprime el resultado
  printf_vector(resultado1, p1.n);
  printf_vector(resultado2, p2.n);
  println;

  return 0;
}



