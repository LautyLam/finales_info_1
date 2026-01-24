/**
	\file    funciones.c
	\brief   Funciones correspondientes a los puntos del final del 13/12/2023
	\author  Hector Spataro (hspataro@frba.utn.edu.ar)
	\date    13/12/2023
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <funciones.h>


//--------------
//-- Defines --
//--------------

//Los 5 bits más significativos (del  59  al  63) para el ID: 1111 1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
//                                                        0x   F    8    0    0    0    0    0    0    0    0    0    0    0    0    0    0
#define mascaraID 0xF800000000000000
//Desplazamiento
#define despID 59

//Los siguientes 23 bits (del 36 al 58) para el timestamp: 0000 0111 1111 1111 1111 1111 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000
//                                                      0x   0    7    F    F    F    F    F    0    0    0    0    0    0    0    0    0
#define mascaraTS 0x7FFFFF000000000
//Desplazamiento
#define despTS 36

//Los siguientes 16 bits (del 20 al 35), para el valor del módulo A: 0000 0000 0000 0000 0000 0000 0000 1111 1111 1111 1111 0000 0000 0000 0000 0000
//                                                                0x   0    0    0    0    0    0    0    F    F    F    F    0    0    0    0    0
#define mascaraMA 0xFFFF00000
//Desplazamiento
#define despMA 20

//Los siguientes 14 bits (del 6 al 19) para el valor del  módulo B: 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 1111 1111 1100 0000
//                                                               0x   0    0    0    0    0    0    0    0    0    0    0    F    F    F    C    0
#define mascaraMB 0xFFFC0
//Desplazamiento
#define despMB 6

//Los últimos 6 bits corresponden al CRC y no serán tenidos en cuenta.

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

int convertir (cliente_t ** listado, unsigned long * datos, int cant)
{
    int i;
    int salida = ERRMEM;
    unsigned long temp;

    *listado = (cliente_t *) malloc (cant * sizeof(cliente_t));

    if (*listado)
    {
        salida = OK;
        for (i = 0; i < cant; i++)
        {
            temp = datos[i] & mascaraID;
            (*listado)[i].aidi = temp >> despID;

            temp = datos[i] & mascaraTS;
            (*listado)[i].timestamp = temp >> despTS;

            temp = datos[i] & mascaraMA;
            (*listado)[i].modA = temp >> despMA;

            temp = datos[i] & mascaraMB;
            (*listado)[i].modB = temp >> despMB;
        }
    }
    
    return salida;
}

//---------------------------------------------------------------------------------------------

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

int cargar (unsigned long ** datos, int * cant, char * nombre)
{
    int file;
    int salida = ERRARCH;
    unsigned long buffer;  
    unsigned long * auxp = NULL;

    *datos = NULL;
    *cant = 0;

    file = open (nombre, O_RDONLY);
    if (file != -1)
    {
        salida = OK;
        while((read(file, &buffer, sizeof(buffer)) > 0) && (!salida))
        {
            auxp = (unsigned long *) realloc (*datos, ((*cant)+1)*sizeof(unsigned long));
            if (auxp)
            {
                *datos = auxp;
                *(auxp+(*cant)) = buffer;
                (*cant)++;
            }
            else
            {
                free(*datos);
                *datos = NULL;
                salida = ERRMEM;
            }
        }
        close(file);
    }
    return salida;
}

//---------------------------------------------------------------------------------------------

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

int guardar (cliente_t * listado, int cant, char * nombre)
{
    int i;
    int salida = ERRARCH;
    FILE * arch = NULL;
    cliente_t aux;

    arch = fopen(nombre, "w");
    if(arch)
    {
        salida = OK;
        for (i = 0; i < cant; i++)
        {
            aux = *(listado+i); //No es necesario, lo hago para que el fprintf no quede tan largo.

//Formato a utilizar -->   ID: 10   s: 4959830   Mod a: 40200   Mod b: 5944
            fprintf(arch, "ID: %3d\ts: %7u\tMod A: %5d\tMod B: %5d\n", aux.aidi, aux.timestamp, aux.modA, aux.modB);
        }
        fclose(arch);
    }

    return salida;
}

//---------------------------------------------------------------------------------------------
