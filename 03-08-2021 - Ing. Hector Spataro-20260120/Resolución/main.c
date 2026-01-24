/*
Punto 4) Realizar un programa que reciba por argumento de main uno o varios nombres de archivos.
Por cada nombre deberá generar un proceso hijo que se encargará de abrirlo y cargarlo en un buffer utilizando la función del punto 3.
Cada proceso deberá convertir el contenido del buffer a texto utilizando la función del punto 1 y generar un nuevo archivo (de texto) con la frase convertida, cuyo nombre sea el generado en la función 2.
Para probar la función main, si no tiene desarrollada la función del punto 1, puede utilizar un string cualquiera en reemplazo de la función.
Para probar la función main, si no tiene desarrollada la función del punto 2, puede utilizar un nombre de archivo cualquiera en reemplazo de la función.
Deberá validar todos los errores posibles presentando por pantalla el mensaje informativo correspondiente en caso de producirse alguno.
El proceso padre, a medida que vaya disparando los hijos, deberá ir completando un vector de estructuras con la información de cada proceso. El tamaño máximo de este vector será de 10 elementos.
Una vez que disparó todos los hijos y completó el vector, quedará en espera.
Finalizará cuando hayan terminado todos los hijos asegurándose que hayan concluido correctamente.

La estructura que utilizará para almacenar la información, será:

struct hijos
{ 
	int pid; 			//Número del proceso hijo generado.
	char * archivo; 	//Nombre del archivo que utiliza dicho proceso.
	int nro_arg;		//Número de orden en el que fue cargado el nombre en la línea de comando.
};

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char **  argv)
{

	int i;
	int pid;
	struct hijos procesos [10];
	char * nombre_vec = NULL;

	if ((argc < 2) || (argc > 10))
	{
		printf("Debe especificar entre uno y diez nombres de archivo para procesar.\n");

	}
	else
	{

		for (i = 1; i < argc; i++)
		{

			pid = fork();

			if (!pid)
			{
				f_hijo (argv[i]);
				return 0;
			}
			else
			{
				nombre_vec = (char *) malloc (strlen(argv[i])+1);
				if (!nombre_vec)
				{
					printf("No se pudo obtener memoria para guardar el nombre (archivo %d).\n", i);
					exit(1);
				}

				strcpy(nombre_vec, argv[i]);

				procesos[i].pid = pid;
				procesos[i].archivo = nombre_vec;
				procesos[i].nro_arg = i;

			}
		}

		for (i = 1; i < argc; i++)
		{
				wait(NULL);
		}

		for (i = 1; i < argc; i++)
		{
				free(procesos[i].archivo);
		}

	}
	return 0;
}

