#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node *next;
};

int main()
{
  struct Node *head = malloc(sizeof(struct Node));
  head->value = 1;
  head->next = malloc(sizeof(struct Node));
  head->next->value = 2; 

  printf("Direccion del primer nodo: %p\n",head);
  printf("Valor del primer nodo: %i\n",head->value);
  
  printf("Direccion del segundo nodo: %p\n", head->next);
  printf("Valor del segundo nodo: %i\n", head->next->value);
}
