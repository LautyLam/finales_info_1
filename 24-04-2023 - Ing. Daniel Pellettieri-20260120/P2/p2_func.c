// Final 24/05/2023
// Propuesta de resolución punto 2
// Funciones
// Ing. Daniel Pellettieri

#include "p2.h"

// Función para apilar un dato
// *p: puntero a pila - *sp: puntero control de pila - c: caracter a apilar
char apilar(char *p, char *sp, char c)
{
    if(*sp<TAM_P)
    {
        p[*sp]=c;
        (*sp)++;
        return 0;
    }
    else
    {
        return 1;
    }
}

// Función para desapilar un dato
// *p: puntero a pila - *sp: puntero control de pila
char desapilar(char *p, char *sp)
{
    if(vacia(p, sp)==1)
    {
        return 1;
    }
    else
    {
        (*sp)--;
        return(p[*sp]);
    }
}


// Función para verificar que la pila esté vacía
char vacia(char *p, char *sp)
{
    if(*sp==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
