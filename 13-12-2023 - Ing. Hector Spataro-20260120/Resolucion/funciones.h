/**
	\file    funciones.h
	\brief   Archivo con las definiciones necesarias para utilizar tanto con el main.c como con el funciones.c
	\author  Hector Spataro (hspataro@frba.utn.edu.ar)
	\date    13/12/2023
	\version 1.0.0
*/

#ifndef FUNCIONES_H
    #define FUNCIONES_H

    //-----------------
    //-- Estructuras --
    //-----------------

    /*
    ID  : Entero sin signo de 8 bits. 
    timestamp  : Entero sin signo de  32 bits  . 
    módulo A  : Entero sin signo de  16 bits  (unsigned short int)  . 
    módulo B  : Entero sin signo de  16 bits (unsigned short int)  . 
    */

    typedef struct CLIENTE
    {
        unsigned char aidi;
        unsigned int timestamp;
        unsigned short modA;
        unsigned short modB;
    } cliente_t;

    //-------------
    //-- Defines --
    //-------------

    #define OK 0
    #define ERRMEM 1
    #define ERRARCH 2
    #define ERRARG 3

    //----------------
    //-- Prototipos --
    //----------------

    /**
        \fn     int convertir (cliente_t ** listado, unsigned long * datos, int cant);
        \brief  Función que recibe un vector de unsigned long y los separa según los campos que lo consituyen gerenado un nuevo vector de estructuras con los valores separados.
        \author  Hector Spataro (hspataro@frba.utn.edu.ar)
        \date    13/12/2023
        \param  cliente_t ** listado: Dirección de memoria donde guardar la dirección de memoria donde comienza el vector de estructuras.
        \param  unsigned long * datos: Dirección de memoria del vector de datos a para separar.
        \param  int cant: Cantidad de datos que posee el vector datos.
        \return Resultado de la función (OK, ERRMEM)
    */
    int convertir (cliente_t ** listado, unsigned long * datos, int cant);
    
    /**
        \fn     int cargar (unsigned long ** datos, int * cant, char * nombre);
        \brief  Función que lee el archivo binario recibido y carga los valores en un vector.
        \author  Hector Spataro (hspataro@frba.utn.edu.ar)
        \date    13/12/2023
        \param  unsigned long ** datos: Dirección de memoria donde guardar la dirección de memoria del vector de datos generado.
        \param  int * cant: Dirección de memoria donde guardar la cantidad de datos que posee el vector datos.
        \param  char * nombre: Dirección de memoria donde comienza el string con el nombre del archivo a leer.
        \return Resultado de la función (OK, ERRMEM, ERRARCH)
    */
    int cargar (unsigned long ** datos, int * cant, char * nombre);

    /**
	\fn     int guardar (cliente_t * listado, int cant, char * nombre);
	\brief  Función que escribe un archivo de texto con los valores separados por cada campo.
	\author  Hector Spataro (hspataro@frba.utn.edu.ar)
	\date    13/12/2023
	\param  cliente_t * listado: Dirección de memoria donde se encuentra el vector de estructuras a guardar en el archivo.
	\param  int cant: Cantidad de elementos del vector de estructuras.
    \param  char * nombre: Dirección de memoria donde comienza el string con el nombre del archivo a grabar.
	\return Resultado de la función (OK, ERRARCH)
    */
    int guardar (cliente_t * listado, int cant, char * nombre);

#endif
