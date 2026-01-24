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
	\file    funciones1.c
	\brief   Desarrollo de las funciones necesarias para cumplir con la resolución del final del 18-FEB-2025
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2025.02.19 
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funciones1.h"

/**
	\fn     void agregoordenado(struct NODO ** lista, struct NODO * agregado);
	\brief  Función que utilizada para generar la nuevas lista con aquellos nodos que cumplan la condición.
			Dado que lo pide ordenado, la incorporación del nodo a la lista ya se hace de esta manera.			
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  struct NODO ** lista: Dirección de la variable que almacenará la dirección de comienzo de la lista. Se pasa por referencia por si 
	la función debe insertar el nodo en el primer lugar.
	\param  struct NODO * agregado: Dirección de memoria donde se encuentra el nodo a agregar.
	\return void: No retorna nada.
*/
void agregoordenado(struct NODO ** lista, struct NODO * agregado)
{
		nodo * auxp = *lista;
		int sigo = SI;

		if(auxp)
		{
			if(strcmp(auxp->str, agregado->str)>0)
			{
				sigo = NO;
				agregado->next = auxp;
				*lista = agregado;
			}

			while(sigo)
			{
				if(auxp->next)
				{
					if(strcmp(auxp->next->str, agregado->str)>0)
					{
						agregado->next = auxp->next;
						auxp->next = agregado;
						sigo = NO;
					}
					else
					{
						auxp = auxp->next;
					}
				}
				else
				{
					agregado->next = NULL;
					auxp->next = agregado;
					sigo = NO;					
				}
			}
		}
		else
		{ 
			*lista = agregado;
			agregado->next = NULL;
		}
	return;
}
//------------------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     struct NODO * NuevaLista ( struct NODO ** h , int clave );
	\brief  Función que recorre la lista y extrae los nodos que cumplen con el criterio para ir cambiandolos de lista.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  struct NODO ** h: Dirección de la variable que almacenará la dirección de comienzo de la lista. Se pasa por referencia por si 
	la función debe quitar el nodo del primer lugar.
	\param  int clave: Valor de la clave que debe considerar para mover el nodo.	
	\return struct NODO *: Dirección de memoria donde se encuentra el primer nodo de la nueva lista creada.
*/
struct NODO * NuevaLista ( struct NODO ** h , int clave )
//Se adecúo el prototipo del enunciado, por si correspondía quitar de la lista el primer elemento. 
//El primer argumento cambió de "struct NODO * h" a "struct NODO ** h" 
{
	nodo * nuevalista = NULL;
	nodo * auxvl = *h;
	nodo * proximo = NULL;

	if(*h)
	{
		while((*h)->clave == clave)
		{
			proximo = (*h)->next;
			agregoordenado(&nuevalista, (*h));
			*h = proximo;
		}
		auxvl = *h;
		while (auxvl->next)
		{
			if(auxvl->next->clave == clave)
			{
				proximo = auxvl->next->next;
				agregoordenado(&nuevalista, auxvl->next);
				auxvl->next = proximo;
			}
			if (auxvl->next)
			{
				auxvl = auxvl->next;
			}
		}		
	}
	return nuevalista;
}
//------------------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     void liberolista(nodo * inicio);
	\brief  Función encargada de liberar la memoria ocupada por los nodos de una lista.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  nodo * inicio: Dirección donde comienza la lista de la cual quiero liberar memoria.
	\return void: No retorna nada.
*/
void liberolista(nodo * inicio)
{
		nodo * auxp = inicio;

		while(inicio)
		{
			auxp = inicio;
			inicio = inicio->next;
			free(auxp);
		}
}
//------------------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     void imprimolista(nodo * inicio);
	\brief  Función encargada de mostrar por pantalla los nodos de una lista.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  nodo * inicio: Dirección donde comienza la lista de la cual quiero mostrar por pantalla.
	\return void: No retorna nada.
*/
void imprimolista(nodo * inicio)
{
	nodo * auxp = inicio;

	printf("-------------------------------------------------------\n");
	while(auxp)
	{
		printf("str: %s - clave: %d\n", auxp->str, auxp->clave);
		auxp = auxp->next;
	}
	printf("-------------------------------------------------------\n");
	return;
}
//------------------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     void escribolista(nodo * inicio, int fd);;
	\brief  Función encargada de escribir en un archivo los nodos de una lista.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  nodo * inicio: Dirección donde comienza la lista de la cual quiero escribir en el archivo.
	\param  int fd: File descriptor del archivo a escribir.
	\return void: No retorna nada.
*/
void escribolista(nodo * inicio, int fd)
{
	nodo * auxp = inicio;

	while(auxp)
	{
		write(fd, auxp->str, strlen(auxp->str));
		write(fd, "\n", 1);
		auxp = auxp->next;
	}
	return;
}
//------------------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     nodo * generolista();
	\brief  Función encargada de generar una lista de valores cualesquiera para probar las otras funciones.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\return nodo *: Dirección de memoria donde arranca la lista generada.
*/
nodo * generolista()
{
	char * palabras[] 	= {"realizar","una","funcion","a","la","que","se","le","pase","como","argumento","el","header","de","la","lista","anteriormente","mencionada", NULL};
	int claves[] 		= {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	int i = 0;
	nodo * lista = NULL;
	nodo * auxp = NULL;
	nodo * nuevo = NULL;

	nuevo = (nodo *) malloc(sizeof(nodo));
	lista = nuevo;	
	while (palabras[i] && nuevo)
	{	
		strcpy(nuevo->str, palabras[i]);
		nuevo->clave = claves[i];
		nuevo->next = NULL; 
		if(palabras[i+1])
		{
			auxp = nuevo;
			nuevo = (nodo *) malloc(sizeof(nodo));
			auxp->next = nuevo;
		}
		i++;
	}
	return lista;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
