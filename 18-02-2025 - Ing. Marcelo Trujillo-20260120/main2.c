/**
	\file    main2.c
	\brief   Archivo que contiene la función principal que utiliza la función pedida en el punto 2.
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2025.02.12 
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"

/**
	\fn      int main (void);
	\brief   Función principal que llama a las funciones desarrolladas.
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2025.02.12 
	\return  int:   vale 0 si estuvo todo bien.
*/
int main (void)
{
	char * palabras[] 	= {"1010101","121266","123456789","1A2B3C4D","1J456","1010101","121266","123456789","1A2B3C4D","1J456","1010101","121266","123456789","1A2B3C4D","1J456","1010101","121266","123456789","1A2B3C4D","1J456",NULL};
	int bases[] 		= {2,2,2,2,2,8,8,8,8,8,10,10,10,10,10,16,16,16,16,16};
	int i = 0;
	int digitos;
	int valor;
	int (*pasar) (char *) = NULL;

	while (palabras[i])
	{
		if(bases[i] == BASE2) pasar = Binario;
		else if(bases[i] == BASE8) pasar = Octal;
		else if(bases[i] == BASE10) pasar = Decimal;
		else if(bases[i] == BASE16) pasar = Hexadecimal;

		valor = pasar(palabras[i]);
		digitos = CantDigitos(palabras[i], pasar);
		printf("String: %s, Base: %d, Valor decimal: %d, Cantidad de digitos: %d\n", palabras[i], bases[i], valor, digitos);
		i++;
	}
	
	return 0;
}
