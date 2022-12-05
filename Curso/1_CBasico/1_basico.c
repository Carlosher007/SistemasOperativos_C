#include <stdio.h>

int main(){
  // printf("Helo world\n"); 
  int a = 5;
  float a = 5.5;
  double a = 5.5; //Mas Precicion que el b
  char a = 'c';
  printf("Variable de a: %i\n",a);
  // el %s significa que va a imprimir una cadena de caracteres
  // el %c significa que va a imprimir un caracter
  // el %i significa que va a imprimir un entero
  // el %f significa que va a imprimir un float
  // el %d significa que va a imprimir un double
  // el %p significa que va a imprimir un puntero

  return 0;
}

// gcc archivo.c -o nombreEjecutable