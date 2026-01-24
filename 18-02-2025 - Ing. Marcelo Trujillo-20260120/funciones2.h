/**
	\file    funciones2.h
	\brief   Archivo de encabezado para utilizar la función que se encuentra en funciones2.c
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2025.02.12 
	\version 1.0.0
*/

#ifndef FUNCIONES2_H
#define FUNCIONES2_H

//-------------
//-- Defines --
//-------------
#define BASE2 2
#define BASE8 8
#define BASE10 10
#define BASE16 16
#define SI 1
#define NO 0

//----------------
//-- Prototipos --
//----------------
/**
	\fn     int Binario ( char * binario );
	\brief  Función encargada de obtener en un entero un numero binario en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * binario: Es el string binario a convertir.
	\return int: Valor en base 10 del numero binario recibido.
*/
int Binario ( char * binario );

/**
	\fn     int Octal ( char * octal );
	\brief  Función encargada de obtener en un entero un numero octal en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * octal: Es el string octal a convertir.
	\return int: Valor en base 10 del numero octal recibido.
*/
int Octal ( char * octal );

/**
	\fn     int Decimal ( char * decimal );
	\brief  Función encargada de obtener en un entero un numero decimal en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * decimal: Es el string decimal a convertir.
	\return int: Valor en base 10 del numero decimal recibido.
*/
int Decimal ( char * decimal );

/**
	\fn     int Hexadecimal ( char * headecimal );
	\brief  Función encargada de obtener en un entero un numero hexadecimal en formato string
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * headecimal: Es el string hexadecimal a convertir.
	\return int: Valor en base 10 del numero hexadecimal recibido.
*/
int Hexadecimal ( char * headecimal );

/**
	\fn     int esvalido (char * cadena, int base);
	\brief  Función encargada de validar si los digitos del string corresponden a la base informada
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date   2025.02.19
	\param  char * cadena: Es el string del numero a validar.
	\param  int base: Es la base sobre la cual calcular los digitos validos.
	\return int: Devuelve SI (1) o NO (0) si es valido o no respectivamente.
*/
int esvalido (char * cadena, int base);

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
int CantDigitos( char * cadena , int ( *pFuncion )( char * ) );

#endif