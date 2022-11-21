#include <stdio.h>
#include <stdlib.h>

struct Punto
{
  double x;
  double y;
};

int main()
{
  // Structs => Coleccion de tipo de datos completos

  struct Punto punto = {0.5, 5.9};            // Inicializarlo en el stack
  struct Punto punto2 = {.y = 5.9, .x = 0.5}; // Inicializarlo sabiendo el nombre en stack
  printf("x:%f, y:%f\n", punto.x, punto.y);

  struct Punto *punto3 = malloc(sizeof(struct Punto)); // Inicializarlo con malloc en el hip
  punto3->x = 0.5;
  punto3->y = 5.9;

  printf("x:%f, y:%f\n", punto3->x, punto3 ->y);

  free(punto3);

}