
// Ahora necesitamos consular que el numero de hilos no se mayor al numero de nucles que tenemos en el computador para eso usamos la funcion sysconf(_SC_NPROCESSORS_ONLN) que nos devuelve el numero de nucles que tenemos en el computador.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h> //uso de hilos
#include <unistd.h>  //uso de sysconf
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
  int *vector;         // vector es un puntero a un arreglo de enteros que sirve para almacenar los valores de fibonacci
  int *resultado;      // resultado es un vector de enteros que sirve para guardar el resultado de la funcion fibonacci
  int n;               // Numero de elementos del vector
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
      mr, // mr: max_random
      n;  // n: numero de hilos
  int *vector;
  int i;
  if (argc != 4)
  {
    printf("Ejecutar de la siguiente manera: \n");
    printf("\t %s <vector_length> <max_random> <n>\n", argv[0]);
    exit(1);
  }
  vl = atoi(argv[1]);
  mr = atoi(argv[2]);
  n = atoi(argv[3]);

  vector = (int *)malloc(sizeof(int) * vl);

  // Se consula el numero de nucles que tenemos en el computador
  int nucles = sysconf(_SC_NPROCESSORS_ONLN);
  // Si el numero de hilos es mayor al numero de nucles se asigna el numero de nucles a la variable n
  if (n > nucles)
  {
    n = nucles;
  }

  srand(time(NULL));
  for (i = 0; i < vl; i++)
  {
    vector[i] = max_random(mr - CONSTANTE, mr);
  }
  printf_vector(vector, vl);
  println;

  // Se crean las variables para los hilos
  pthread_t hilos[n];
  // Se crean las estructuras para pasar los parametros a la funcion que se ejecutara en el hilo
  struct parametros parametros[n];
  // Se crean los vectores para guardar los resultados de la funcion que se ejecutara en el hilo
  int *resultados[n];
  // Se asignan los valores
  for (i = 0; i < n; i++)
  {
    parametros[i].vector = vector + (i * (vl / n));
    parametros[i].n = vl / n;
    parametros[i].funcion = fibonacci;
    resultados[i] = (int *)malloc(sizeof(int) * parametros[i].n);
    parametros[i].resultado = resultados[i];
  }

  // Se crean los hilos
  for (i = 0; i < n; i++)
  {
    pthread_create(&hilos[i], NULL, funcion_hilo, &parametros[i]);
  }

  // Se espera a que los hilos terminen
  for (i = 0; i < n; i++)
  {
    pthread_join(hilos[i], NULL);
  }

  // Se imprime el resultado
  for (i = 0; i < n; i++)
  {
    printf_vector(resultados[i], parametros[i].n);
    println;
  }

  return 0;
}
