#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*c
Final
*/
/*===================================================*/
typedef struct consumo {
	char nombreyapellido[80];
	unsigned int codigoCliente;
	float kws;
} ENERGIA;
/*===================================================*/
typedef struct listado{
	ENERGIA cliente;
	struct listado *siguiente;
} LISTAENERGIA;
/*===================================================*/
int obtenerBarrio(unsigned int, unsigned int *);
int crearListado(LISTAENERGIA **, FILE*,unsigned int);
int obtenerRegistro(FILE *, ENERGIA *);
#define BARRIO_FILTRO 1
/*===================================================*/
