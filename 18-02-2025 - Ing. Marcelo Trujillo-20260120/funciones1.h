/**
	\file    funciones1.h
	\brief   Archivo de encabezado para utilizar las funciones que se encuentran en funciones1.c
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2025.02.19 
	\version 1.0.0
*/

#ifndef FUNCIONES1_H
#define FUNCIONES1_H

//-----------------
//-- Estructuras --
//-----------------

struct NODO
{ 
	char str[20]; 
	int clave; 
	struct NODO * next;
};

typedef struct NODO nodo;

//-------------
//-- Defines --
//-------------
#define SI 1
#define NO 0

//----------------
//-- Prototipos --
//----------------

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
void agregoordenado(struct NODO ** lista, struct NODO * agregado);

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
struct NODO * NuevaLista ( struct NODO ** h , int clave );

/**
	\fn     void liberolista(nodo * inicio);
	\brief  Función encargada de liberar la memoria ocupada por los nodos de una lista.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  nodo * inicio: Dirección donde comienza la lista de la cual quiero liberar memoria.
	\return void: No retorna nada.
*/
void liberolista(nodo * inicio);

/**
	\fn     void imprimolista(nodo * inicio);
	\brief  Función encargada de mostrar por pantalla los nodos de una lista.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  nodo * inicio: Dirección donde comienza la lista de la cual quiero mostrar por pantalla.
	\return void: No retorna nada.
*/
void imprimolista(nodo * inicio);

/**
	\fn     void escribolista(nodo * inicio, int fd);;
	\brief  Función encargada de escribir en un archivo los nodos de una lista.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  nodo * inicio: Dirección donde comienza la lista de la cual quiero escribir en el archivo.
	\param  int fd: File descriptor del archivo a escribir.
	\return void: No retorna nada.
*/
void escribolista(nodo * inicio, int fd);

/**
	\fn     nodo * generolista();
	\brief  Función encargada de generar una lista de valores cualesquiera para probar las otras funciones.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\return nodo *: Dirección de memoria donde arranca la lista generada.
*/
nodo * generolista();

#endif