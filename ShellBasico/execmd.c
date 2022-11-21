/* Archivo responsable de manejar la ejecuición del comando */

#include "main.h"

void execmd(char **argv)
{
  char *command = NULL; //El comando empieza siendo null

  if(argv){
    /* Obtenemos el comando, que sería el primer elemento */
    command = argv[0];

    /* Ejecutar el comando con execve */
    if(execve(command,argv,NULL)==-1){
      perror("Error:");
    }
  }
}

/* Execve : Esto hace que el programa que está ejecutando actualmente el proceso de llamada sea reemplazado por un nuevo programa..
  => pathname : representa el comando que se ingresa
  => argv : matriz
  => en
*/
/* Variables de entorno: => Con la variable global environ */