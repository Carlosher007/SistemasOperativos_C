#include "main.h"

int main(int ac, char **argv)
{
  /* Declaramos las variables */
  char *prompt = "(Eshell) $ "; // Mensaje del inicio
  char *lineptr = NULL;         // Aquí se almacenara lo escrito
  char *lineptr_copy = NULL;    // Variable para contenedor los delimitadores
  size_t n = 0;                 // Almacenar el tamaño asignado en bytes
  ssize_t nchars_read;          // Numero de caracteres del getline, -1 si falla
  const char *delim = " \n";    // delimitador del strtok
  int num_tokens = 0;           // Variable para tokens, numero de tokens
  char *token;                  // subcadena de la cadena lineptr
  int i;                        // iterator

  /*Declarando void variables*/
  (void)ac;

  /* Crear un bucle infinito para la shell */
  while (1)
  {
    /* Inicial */
    printf("%s", prompt);                       // Imprime el msg inicial
    nchars_read = getline(&lineptr, &n, stdin); // Obtenemos el numero de caracteres de getline y lo guardamos en lineptr

    /* Check si getline fallo */
    if (nchars_read == -1)
    {
      printf("Exiting shel... \n");
      return (-1);
    }

    /* Asignar espacio dinamicamente para almacenar una copia de lineptr */
    lineptr_copy = malloc(sizeof(char) * nchars_read); // Espacio de un caracter por el numero de caracteres leidos
    if (lineptr_copy == NULL)
    {
      perror("tsh: memory allocation error");
      return (-1);
    }

    /* Copiar lineptr a linptr_copy */
    strcpy(lineptr_copy, lineptr); // puntero al espacio asignado y la cadena a copiar

    /* Separar el string lineptr en un array de palabras */
    token = strtok(lineptr, delim); // subpalabra de lineptr

    /* Determinar el numero de tokens */
    while (token != NULL)
    {
      num_tokens++;
      token = strtok(NULL, delim);
    }
    num_tokens++;

    /* Asigne espacio para contener la matriz de cadenas o tokens */
    argv = malloc(sizeof(char *) * num_tokens);

    /* Almacene cada token en la matriz argv */
    token = strtok(lineptr_copy, delim);

    for (i = 0; token != NULL; i++)
    {
      argv[i] = malloc(sizeof(char) * strlen(token));
      strcpy(argv[i], token);

      token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    /* Si no falla getline imprimimos lo que se escribio */
    printf("%s\n", lineptr);

    /* Ejecutar el comando */
    execmd(argv);
  }

  free(lineptr);      // Liberar espacio en memoria
  free(lineptr_copy); // Liberar espacio en memoria

  return (0);
}

/*
Tokenizacion: convertir una cadena en tokens de cadenas => strtok
char *strtok(char *str, const char *delim);
  str => cadena a tokenizar
  delim => delimitador para separar
*/
/* getline retorna el número total de caracteres que leyo la funcion. Si falla retorna -1, o si encuentra un caracter EOF (usar ctrl+d)*/
