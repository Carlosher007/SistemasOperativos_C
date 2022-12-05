#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Declarar un puntero
  int a = 5;
  int *pointer_a = &a; // Apunta a una direccion de memoria, no a un valor
  // & => Para sacar la direccion de memoria
  int *another_pointer = pointer_a;

  printf("Valor del puntero: %p\n", pointer_a);
  printf("Valor de otro puntero : %p\n", another_pointer);
  printf("Valor donde apunta el puntero : %i\n", *pointer_a);

  // Cambiar valor de a a traves de puntero
  *pointer_a = 12;

  // Liberamos la zona de memoria
// free(pointer_a);
// free(another_pointer);
}