/*
Realizar las siguientes funciones:
    • Recibe una String con la representación de un numero en base 2 y devuelve su 
	valor de forma entera en base 10.
int Binario ( char *binario );
    • Recibe una String con la representación de un numero en base 8 y devuelve su 
	valor de forma entera en base 10.
int Octal ( char *octal );
    • Recibe una String con la representación de un numero en base 10 y devuelve su
	valor de forma entera en base 10.
int Decimal ( char *decimal );
    • Recibe una String con la representación de un numero en base 16 y devuelve su
	valor de forma entera en base 10.
int Hexadecimal ( char *headecimal );

Realizar una función que tenga el siguiente prototipo
int CantDigitos( char *  , int ( *pFuncion)( char *) );
reciba un puntero a char que señale a la string a convertir y un puntero a función que permita recibir las direcciones de las funciones del punto 2A y retorne la cantidad de dígitos del número convertido.
*/

/**
	\file    funciones2.c
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
#include <ctype.h>
#include "funciones2.h"

/**
	\fn     int Binario ( char * binario );
	\brief  Función encargada de obtener en un entero un numero binario en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * binario: Es el string binario a convertir.
	\return int: Valor en base 10 del numero binario recibido.
*/
int Binario ( char * binario )
{
	int i = 0, resu = 0;
	int termino;

	if(esvalido(binario, BASE2))
	{
		while(*(binario+i))
		{	
			termino = *(binario+i)-'0';
			resu = resu*BASE2+termino;
			i++;
		}
	}
	return resu;
}
//------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     int Octal ( char * octal );
	\brief  Función encargada de obtener en un entero un numero octal en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * octal: Es el string octal a convertir.
	\return int: Valor en base 10 del numero octal recibido.
*/
int Octal ( char * octal )
{
	int i = 0, resu = 0;
	int termino;

	if(esvalido(octal, BASE8))
	{
		while(*(octal+i))
		{	
			termino = *(octal+i)-'0';
			resu = resu*BASE8+termino;
			i++;
		}
	}
	return resu;
}
//------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     int Decimal ( char * decimal );
	\brief  Función encargada de obtener en un entero un numero decimal en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * decimal: Es el string decimal a convertir.
	\return int: Valor en base 10 del numero decimal recibido.
*/
int Decimal ( char * decimal )
{
	int i = 0, resu = 0;
	int termino;

	if(esvalido(decimal, BASE10))
	{
		while(*(decimal+i))
		{	
			termino = *(decimal+i)-'0';
			resu = resu*BASE10+termino;
			i++;
		}
	}
	return resu;
}
//------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     int Hexadecimal ( char * headecimal );
	\brief  Función encargada de obtener en un entero un numero hexadecimal en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * headecimal: Es el string hexadecimal a convertir.
	\return int: Valor en base 10 del numero hexadecimal recibido.
*/
int Hexadecimal ( char * headecimal )
{
	int i = 0, resu = 0;
	int termino;

	if(esvalido(headecimal, BASE16))
	{
		while(*(headecimal+i))
		{	
			if(*(headecimal+i) >= '0' && *(headecimal+i) <= '9')
			{
				termino = *(headecimal+i)-'0';
			}
			else
			{
				termino = toupper(*(headecimal+i))-'A'+10;
			}
			resu = resu*BASE16+termino;
			i++;
		}
	}
	return resu;
}
//------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     int esvalido (char * cadena, int base);
	\brief  Función encargada de validar si los digitos del string corresponden a la base informada
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * cadena: Es el string del numero a validar.
	\param  int base: Es la base sobre la cual calcular los digitos validos.
	\return int: Devuelve SI (1) o NO (0) si es valido o no respectivamente.
*/
int esvalido (char * cadena, int base)
{
	int resu = SI, i = 0;

	while (*(cadena+i) && resu)
	{
		if((base == BASE2) || (base == BASE8) || (base == BASE10))
		{
			if ((*(cadena+i)<'0') || (*(cadena+i) > ('0' + base - 1)))
			{
				resu = NO;
			}
		}
		else if (base == BASE16)
		{
			if ((*(cadena+i) < '0') || (*(cadena+i) > '9'))
			{
				if ((toupper(*(cadena+i)) < 'A') || (toupper(*(cadena+i) > 'F')))
				{
					resu = NO;
				}
			}
		}
		else
		{
			resu = NO;
		}
		i++;
	}
	return resu;
}
//------------------------------------------------------------------------------------------------------------------------------------

/**
	\fn     int CantDigitos( char * cadena , int ( *pFuncion)( char *) );
	\brief  Función encargada de contar la cantidad de digitos decimales de un numero a partir de un string en distintas bases.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * cadena: Es el string del numero a contar los dígitos.
	\param  int  ( *pFuncion )( char * ): Puntero a función que almacena la dirección de la función necesaria para pasar el 
											numero del string a decimal.
	\return int: Devuelve la cantidad de dígitos del valor en base 10.
*/
int CantDigitos( char * cadena , int ( *pFuncion )( char * ) )
{
	int valor, cantdigi = 1;

	valor = pFuncion(cadena);

	while(valor > 9)
	{
		cantdigi++;
		valor/=BASE10;
	}
	return cantdigi;
}
//------------------------------------------------------------------------------------------------------------------------------------

