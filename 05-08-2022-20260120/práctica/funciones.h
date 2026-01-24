#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX 200
void desencriptar_texto (const char * src, char * dst, int desplazamiento);
int aleatorio (int base, int rango);
int desplazar_letras (const char * src, char * dst);
void encriptar_numeros (const char * src, char * dst);
void octal (int numero, char * str);
void string_reverse (char * str);
int encriptar (const char * src, char * dst);

typedef struct encriptado
{
	
	char txt[MAX];
	int desplazamiento;
}encriptado_t;

