// Final 24/05/2023
// Verifica Archivo de datos contra archivo de bytes de verificacion
// main()
// Ing. Daniel Pellettieri


// Archivos de trabajo:
// verif.vvv: archivo de verificadores
// datos_1.ddd: archivo corrupto con 1 error
// datos_3.ddd: archivo corrupto con 3 errores
// datos_5.ddd: archivo corrupto con 5 errores
// datos_OK.ddd: archivo SIN ERRORES (solo a fines de prueba)


#include "p1.h"
#define TAMS 25

int main(void)
{
    int errores;
    char f1[TAMS], f2[TAMS];

    printf("Archivo corrupto: ");
    __fpurge(stdin);
    //gets(f1);
    fgets(f1, TAMS, stdin);
    corrige_fgets(f1);

    printf("Archivo verificador: ");
    __fpurge(stdin);
    //gets(f2);
    fgets(f2, TAMS, stdin);
    corrige_fgets(f2);

    errores=verif(f1, f2);
    printf("\nErrores= %d", errores);

    printf("\n\n");
    return 0;
}
