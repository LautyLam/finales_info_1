
/**
	\file    main.c
	\brief   Archivo con la función main para probar las funciones del final de 13/12/2023
	\author  Hector Spataro (hspataro@frba.utn.edu.ar)
	\date    13/12/2023
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>

#include <funciones.h>

/**
	\fn      int main (int argc, char ** argv);
	\brief   Función main para probar las funciones del final de 13/12/2023
	\author  Hector Spataro (hspataro@frba.utn.edu.ar)
	\date    13/12/2023
	\param   int argc: cantidad de argumentos de main recibidos
	\param   char ** argv: vector de strings con los argumentos de main recibidos
	\return  código de error a partir del comportamiento de las funciones (OK, ERRARG, ERRARCH o ERRMEM)
*/

int main (int argc, char ** argv)
{

    int salida = ERRARG;
    cliente_t * listado = NULL;
    unsigned long * datos = NULL;
    int cant = 0;

    if (argc == 3)
    {
        salida = cargar (&datos, &cant, argv[1]);
        if (!salida) salida = convertir (&listado, datos, cant);
        if (!salida) salida = guardar (listado, cant, argv[2]);
        if (listado) free (listado);
        if (datos) free (datos);
    }

    if (!salida) printf("Todo se pocesó correctamente\n");
    else if (salida == ERRARG)  printf("Cantidad de argumentos incorrecta\n");
    else if (salida == ERRARCH) printf("Error en el manejo de archivos\n");
    else if (salida == ERRMEM)  printf("Error en el manejo de memoria\n");

    return salida;
}

//---------------------------------------------------------------------------------------------