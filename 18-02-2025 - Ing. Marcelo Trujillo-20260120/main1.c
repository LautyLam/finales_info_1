/*
Se dispone de una lista simple cuyos nodos tienen la siguiente estructura: 
struct NODO
{ 
	char str[20]; 
	int clave; 
	struct NODO * next;
};
Realizar una función a la que se le pase como argumento el header de la lista anteriormente mencionada y un valor del campo denominado clave y que devuelva el valor del header de una nueva lista ordenada de menor a mayor formada por los nodos que contengan los strings de la primera cuyo campo clave coincida con el pasado como argumento.

struct NODO * NuevaLista ( struct NODO * h , int clave );
NO SE DEBE PEDIR MEMORIA PARA LA NUEVA LISTA.

Una vez conformada la nueva lista guardar las strings en un archivo cuyo nombre sea ingresado por la línea de 
comandos.
La lista original deberá quedar sin los nodos que fueron transferidos a la nueva lista.
*/

/**
	\file    main1.c
	\brief   Archivo que contiene la función principal que utiliza la función pedida en el punto 1 y utiliza argumentos de main.
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2025.02.19 
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "funciones1.h"

/**
	\fn      int main (int argc, char ** argv);
	\brief   Función principal que llama a las funciones desarrolladas.
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2025.02.19 
	\param   int argc: Cantidad de argumentos recibidos en la línea de comando.
	\param   char ** argv: Vector de strings con cada uno de los argumentos recibidos. Debe recibir un nombre de archivo y una clave a buscar exclusivamente
	\return  int:   vale 0 si estuvo todo bien.
*/
int main (int argc, char ** argv)
{
	int laclave;
	int fd;
	nodo * lista = NULL;
	nodo * filtro = NULL;

	if(argc != 3)
	{
		printf("Cantidad de parametros erronea.\n");		
	}
	else
	{
		laclave = atoi(argv[2]);

		fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC);
		if(fd)
		{
			lista = generolista();
			imprimolista(lista);
			filtro = NuevaLista(&lista, laclave);
			imprimolista(lista);
			imprimolista(filtro);
			escribolista(filtro, fd);
			liberolista(lista);
			liberolista(filtro);
			close(fd);
		}
		else
		{
			printf("Error abriendo el archivo.\n");
		}

	}
	return 0;
}
