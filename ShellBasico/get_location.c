#include "main.h"

char *get_location(char *command)
{
  char *path;           /*A <path> le asignaremos la ruta obtenida de las variables de entorno, es decir, lo que retorne getenv() */
  char *path_copy;      /* Copia de <path> */
  char *path_token;     /* tokens del PATH*/
  char *file_path;      /* ALmacenar la longitud final del archivo path*/
  int command_length;   /* Almacenar la longitud del comando*/
  int directory_length; /* Almacenar la longitud de cada token del strtok*/
  struct stat buffer;   /* Variable que sirve como buffer onde se realizaran las pruebas*/

  path = getenv("PATH"); /*Asignamos el valor de la variable de entorno a path*/

  if (path)
  {
    path_copy = strdup(path);         /*Copia con memoria dinamica de path a path_copy, hay que liberar la memoria*/
    command_length = strlen(command); /*Obtenemos la longitud del comando que se paso*/

    path_token = strtok(path_copy, ":"); /*Usamos strtok con : como delimitador con path_copy. Se hace para obtener todos los directorios disponibles de la variable PATH*/

    /*Se debe verificar que no se halla llegado al final de la variable de la ruta, es decir, que el strtok no ha devuelto NULL*/
    while (path_token != NULL)
    {
      /*longitud del comando*/
      directory_length = strlen(path_token);

      /*Asignar memoria para almacenar el nombre del comando junto con el nombre del directorio*/
      file_path = malloc(command_length + directory_length + 2); /*Longitud final del archivo path.Añadimos 2 debido al < / > y el < \0 > o null caracter que se añadira en el comand*/

      /*Para constuir la ruta del comando, copiamos la ruta del directorio y la concatemaos al comando*/
      strcpy(file_path, path_token); /*Copiamos el token obtenido en file_path*/
      strcat(file_path, "/");        /*Colocamos el /*/
      strcat(file_path, command);    /*Colocamos el command*/
      strcat(file_path, "\0");       /*Colocamos \0*/

      /*Probar que la ruta de file_path (file path actually) existe, si es así lo retornamos, de otra forma seguimos con el siguiente directorio*/
      if (stat(file_path, &buffer) == 0) /*0 significa que el file_path es valido*/
      {
        /*liberamos la memeoria antes de retornar el file_path*/
        free(path_copy);
        return (file_path);
      }
      else
      {
        /*Libreamois la memoria de file_path para intentar con otro path*/
        free(file_path);
        path_token = strtok(NULL, ":");
      }
      /*Si no existe debemos descartar lo almacenado en file_path y generar una nueva file_path con el siguiente directorio si aun no hemos probado todos los directorios del PATH. Si no obtenemos coincidencias despues de revisar todos los directorios y salir del whilñe, devolvemos el comando tal como se paso.*/
    }
    /*Si no obtenemos ningun file_path valido, retornamos null, libreando la memoria del path_copy*/
    free(path_copy);
    /*Antes de salir, veamos si el comando por si mismo es un file_path que si existe*/
    if (stat(command, &buffer) == 0)
    {
      return (command);
    }
    return (NULL);
  }
  return (NULL);
}

/*Para obtener la variable de entorno PATH => getenv()
Busca en la lista de entornos  para encontrar el nombre de la variable de entorno especifico que se pasa como argumento
char *getenv(const char *name) => Punto al valor del entorno o NULL si no hay coincidencia*/

/*Para obtener la ruta  de cada comando, usaremos strtok, funcion que por naturaleza esa destructiva. Pues divide una cadena en sus palabras componentes o en funcion de un delimitador*/
/*Con strdup() podemos crear facilmente una copia de path
Lo que hace es asignar memoria dinamicamente por usted, asi que hay que liberar esa memoria*/

/*GENERAR LA RUTA PARA EL COMANDO*/
/*1. Obtener la longitud del comando*/
/*2. Desglose la variable path_copy en tokens individuales, las cuales estan separadas por < : >*/
/*3. Bucle while para obtener y probar la ruta exacta del comando
Se debe verificar que no se halla llegado al final de la variable de la ruta, es decir, que el strtok no ha devuelto NULL
Para cada camino obtenido al descomponer path_copy, se debe asignar memoria para una nueva cadena que los contenga pues se agregara una barra diagonal, el comando y un caracter de terminación NULL
Esto se hara con malloc, pero se necesita saber el tamaño exacto a asignar. Se procede a encontrar la longitud de cada ficha obtenida de strtok y agrega el numero 2 ya que vamos a introducir dos caracteres adicionales
Luetgo usamos <strcpy> para copiar el token ovbtenido en el file_path. Se añade /,cammnd,\0 en el orden respectivo con strcat*/

/* star => int stat(const char *pathname, struct stat *statbuf)
Esta funcion ayudara a probar si la ruta del archivo que hemos creado existe o no
Devuelve cero cuando accede con exito al ruta, en caso contrario, -1
*/