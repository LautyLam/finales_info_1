
#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
Punto 1) Realizar una función que reciba un buffer de enteros y los convierta a un string.
Considerar que los enteros son de 4 bytes y los valores correspondientes al código ASCII son los 8 bits del medio, es decir 12 bits que no importan, 8 bits con el código ASCII y 12 bits que no importan.
Definir el prototipo que considere más conveniente sabiendo que debe recibir un vector de enteros, su longitud y devolver un string. También deberá tener la opción de retornar un código de error en caso de no poder generar la frase.
Para probar la función puede definir el vector: 
int v[4]={147456,227328,221184,198656};
que dará como resultado la frase “Hola”.

*/

int convertir (int * listado, int largo, char * frase)
{

	int i, codigo = OK;
	int aux_i;
	char aux;

	for (i=0; i < largo; i++)
	{
		aux_i = *(listado+i);
//		aux_i = aux_i >> DESPLAZ;
		aux_i = aux_i / UNBYTE;
		aux = (char) aux_i;
		*(frase+i) = aux;
	}

	*(frase+largo) = '\0';

	return codigo;
}


/*
Punto 2) Realizar una función que reciba un string correspondiente a un nombre de archivo, busque el último punto a la derecha y devuelva un string que corresponda al nombre original, agregada la frase “_decrypt” y la extensión.
Ejemplo: Recibe el nombre "texto.txt" y debe retornar "texto_decrypt.txt" 
Si el nombre no contiene punto, la frase se agregará al final y quedará sin punto.
El prototipo de la función deberá ser:
				int nvo_nombre (char *, char *);
Donde el primer parámetro es el nombre del archivo original, el segundo es el nombre del archivo nuevo y retorna un OK o ERROR (dos constantes simbólicas que deberá definir como 0 y 1) si lo pudo procesar o no.

*/


int nvo_nombre (char * origen, char * destino)
{
	int i, codigo = OK;
	char agregar[] = "_decrypt";

	i = strlen(origen);

	while((*(origen+i) != '.') && (i >= 0))
	{
		i--;
	}

	if (i < 0)
	{
		strcpy(destino,origen);
		strcat(destino, agregar);
	}
	else
	{
		strncpy(destino, origen, i);
		*(destino+i+1) = '\0';
		strcat(destino, agregar);
		strcat(destino, (origen+i));
	}

	return codigo;
}


/*
Punto 3) Realizar una función que reciba el nombre de un archivo. El archivo es del tipo binario y contiene una sucesión de números enteros de 4 bytes. No se conoce previamente su longitud.
La función deberá leer el archivo número por número e ir guardando los valores en un buffer de enteros que será devuelto como resultado de la función a través de una argumento pasado por referencia.
El prototipo de la función deberá ser:
				int lectura (char *, int **);
Donde el primer parámetro es el nombre del archivo, y el segundo es el lugar para guardar la dirección de memoria donde comienza el buffer. Retornará un número mayor o igual a cero con la cantidad de elemento del vector o ERR_LEC (constante simbólica que deberá definir como -1)si no lo pudo generar.

*/

int lectura (char * archivo, int ** buffer)
{

	FILE * lectura;
	int i = 0, aux;
	int * aux_p;

	(*buffer) = (int *) malloc (sizeof(int));
	if (!(*buffer))
	{
		return ERR_LEC;
	}

	lectura = fopen(archivo, "r");
	if (!lectura)
	{
		return ERR_LEC;
	}

	do
	{
		fread(&aux, sizeof(int), 1, lectura);
		if (!feof(lectura))
		{
			aux_p = (int *) realloc (*buffer, sizeof(int)*(i+1));
			if (aux_p)
			{
				(*buffer) = aux_p;
				*((*buffer)+i) = aux;
				i++;
			}
			else
			{
				free(*buffer);
				return ERR_LEC;
			}
		}
	} while (!feof(lectura));

	return i;
}

/*
Función hijo para que el main no sea tan grande
*/

int f_hijo (char * archivo)
{

	int largo, sigo;
	int * numeros;
	char * frase = NULL;
	FILE * destino = NULL;
	char * nombre_dest = NULL;

	largo = lectura (archivo, &numeros);

	if (largo < 0)
	{
		printf("No se pudo generar el vector de números (archivo %s).\n", archivo);
		exit(1);
	}

	nombre_dest = (char *) malloc (strlen(archivo)+DECRYPT+1);
	if (!nombre_dest)
	{
		printf("No se pudo obtener memoria para generar el nombre (archivo %s).\n", archivo);
		exit(1);
	}

	sigo = nvo_nombre (archivo, nombre_dest);
	if (sigo == ERROR)
	{
		printf("Error en la función de generación del nombre (archivo %s).\n", archivo);
		exit(1);
	}

	frase = (char *) malloc (largo+1);
	if (!frase)
	{
		printf("No se pudo obtener memoria para guardar la frase (archivo %s).\n", archivo);
		exit(1);
	}

	sigo = convertir (numeros, largo, frase);
	if (sigo == ERROR)
	{
		printf("Error en la función de conversión de la frase (archivo %s).\n", archivo);
		exit(1);
	}

	destino = fopen(nombre_dest,"w");
	if (!destino)
	{
		printf("No se pudo abrir el archivo para grabar la frase (archivo %s).\n", archivo);
		exit(1);
	}
	fprintf(destino,"%s", frase);

	sleep(10);

	free(frase);
	free(numeros);
	free(nombre_dest);

	fclose(destino);

	return 0;
}
