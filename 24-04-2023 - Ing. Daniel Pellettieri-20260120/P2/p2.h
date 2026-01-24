// Final 24/05/2023
// Propuesta de resolución punto 2
// Header
// Ing. Daniel Pellettieri

#include <stdio.h>
#define TAM_P 20        //Tamaño de la pila
#define TAM_EXP 100     //Tamaño del string que contiene la expresión

// Prototipos
// Función para apilar un dato
// *p: puntero a pila - *sp: puntero control de pila - c: caracter a apilar
char apilar(char *p, char * sp, char c);

// Función para desapilar un dato
// *p: puntero a pila - *sp: puntero control de pila
char desapilar(char *p, char *sp);

// Función para verificar que la pila esté vacía
// *p: puntero a pila - *sp: puntero control de pila
char vacia(char *p, char *sp);
