// Final 24/05/2023
// Verifica Archivo de datos contra archivo de bytes de verificacion
// Funciones
// Ing. Daniel Pellettieri

#include "p1.h"

// Determina el byte de verificacion
// (*s: puntero a char - c: cantidad de bytes de la estructura / union)
unsigned char paridad(char *s, int c)
{
    int i;
    unsigned char b;
    // La funcion es simplemente un bucle que hace un exor con cada uno de los bytes en forma consecutiva

    for(i=0, b=0; i<c; i++)
    {
        //printf("%c", par.bytes[i]);
        b^=s[i];
    }
    // Lo que devuelvo es el byte de verificación
    return b;
}


// compara el byte de verificacion del archivo corrupto con el almacenado en verif.fff
// *f1: nombre del archivo a verificar (corrupto) - *f2: Nombre del archivo con los bytes de verificación
int verif(char *f1, char *f2)
{
    union verif par;
    int fd1, fd2, leidos;
    unsigned char byte_verif_f1, byte_verif_f2;
    // byte_verif_f1: es el verificador que obtendo del archivo corrupto (f1)
    // byte_verif_f2: es el verificador que leo del archivo de verivadores (f2)

    int cont=0;

    // Abro archivo corrupto en modo solo lectura
    if((fd1=open(f1,O_RDONLY))==-1)
    {
        perror("No se puede abrir el archivo");
        return(-1);
    }

    // Abro archivo de verificadores en modo solo lectura
    if((fd2=open(f2,O_RDONLY))==-1)
    {
        perror("No se puede abrir el archivo");
        return(-1);
    }

    // Leo el PRIMER registro del archivo corrupto (lo leo como estructura - miembro d de la union)
    leidos=read(fd1, &par.d, sizeof(par.d));
    // Si lo leyó...
    while(leidos)
    {
        //impresión del registro a fines de probar que estoy leyendo bien
        //printf("\n%s  %d   %.2f\n", par.d.user_name, par.d.user_code, par.d.user_fee);

        // Obtengo el  byte de verificación
        // Observe que ahora lo manejo como vector de char (miembro bytes de la union)
        byte_verif_f1=paridad(par.bytes, sizeof(struct datos));

        //leo un byte de verificacion del archivo de verificadores
        read(fd2, &byte_verif_f2, sizeof(byte_verif_f2));

        //printf("\n%X  %X", byte_verif_f1, byte_verif_f2);

        //Si no son iguales, cuento 1 error
        if(byte_verif_f1!=byte_verif_f2)
            cont++;

        //Leo desde el SEGUNDO registro del archivo corrupto hasta el último(lo leo como estructura - miembro d de la union)
        leidos=read(fd1, &par.d, sizeof(par.d));
    }

    close(fd1);
    close(fd2);
    return cont;
}

void corrige_fgets(char *s)
{
    // "Pisamos" el '\n' con '\0'

    int len;
    len=strlen(s);
    s[len-1]='\0'; // *(s-len-1)='\0';
}


