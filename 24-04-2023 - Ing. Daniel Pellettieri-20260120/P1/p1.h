// Final 24/05/2023
// Verifica Archivo de datos contra archivo de bytes de verificacion
// Header del proyecto
// Ing. Daniel Pellettieri


#include <stdio.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Estructura de datos para lectura del archivo data.ddd */

struct datos
{
    int user_code;
    char user_name[15];
    float user_fee;
};

/* Union entre la estructura y un vector de char para facilitar la obtención del byte de verificacion */

union verif
{
    struct datos d;
    char bytes[sizeof(struct datos)]; //para acceder a cada byte individual del registro leido
};

/* Protipos */

// Determina el byte de verificacion
// (*s: puntero a char - c: cantidad de bytes de la estructura / union)
unsigned char paridad(char *s, int c);

// compara el byte de verificacion del archivo corrupto con el almacenado en verif.fff
// *f1: nombre del archivo a verificar (corrupto) - *f2: Nombre del archivo con los bytes de verificación
int verif(char *f1, char *f2);

// "Corrige" el string ingresado con fgets(), eliminando el '\n' al final del mismo
void corrige_fgets(char *);
