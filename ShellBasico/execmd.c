/* Archivo responsable de manejar la ejecución del comando */

#include "main.h"

void execmd(char **argv)
{
  char *command = NULL; /* // El comando empieza siendo null */
  char *actual_command = NULL;

  if (argv)
  {
    /* Obtenemos el comando, que sería el primer elemento */
    command = argv[0];

    /* Generar la ruta de este comando antes de pasarlo a execve */
    actual_command = get_location(command);

    /* Ejecutar el comando con execve */
    if (execve(actual_command, argv, NULL) == -1)
    {
      perror("Error:");
    }
  }
}

/* Execve : Esto hace que el programa que está ejecutando actualmente el proceso de llamada sea reemplazado por un nuevo programa..
  => pathname : representa el comando que ingresa el usuario final
  => argv : matriz o lista de strings
  Los pathname estaran en argv[0]
  => envp : Cuando execve se ejecuta, comprueba el tercer argumento (envp) proporcionado para ver  si realmente existe una ruta como la que se proporcionó. Si existe, se ejecuta, si no, devuelve -1
*/
/* Variables de entorno: => Variables que se crean y mantienen a nivel del sistema operativo => Con la variable global environ */
/*
execve(command,argv,NULL) => Se pone NULLL pues no nos preocupa por ajora las variables de entonro
*/
/*Ruta exacta de cualquier comando: which <command> */