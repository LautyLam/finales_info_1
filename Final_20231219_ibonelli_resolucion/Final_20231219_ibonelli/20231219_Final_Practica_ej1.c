#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sock-lib.h"

#define MAXDATASIZE 4096 /* maxima cantidad de bytes que puede recibir en una transaccion*/

int main(int argc, char * argv[]) {
	int sock_client;		/* File Descriptor para sockets */
	int numbytes;			/* Contendra el numero de bytes recibidos por read() */
	char buf[MAXDATASIZE];	/* Buffer donde se reciben los datos de read() */
	long recibidos;
	FILE *fp;

	/* Tratamiento de la li­nea de comandos. */
	if (argc < 2) {
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
	}

	sock_client = conectar(argc, argv);

	/* Recibimos los datos del servidor del archivo a abrir */
	if ((numbytes = read(sock_client, buf, MAXDATASIZE)) == -1) {
		perror("error de lectura en el socket");
		exit(1);
	}

	// Recibimos en buf el nombre del archivo
	fp = fopen(buf,"w");

	/* Envio de mensaje READY al servidor */
	char mensajeInicial[] = "READY";
	if(write(sock_client,mensajeInicial,sizeof(mensajeInicial)) == -1) {
		perror("Error en la escritura del socket");
		exit(1);
	}

	recibidos = 0;
	do {
		/* Recibimos los datos del servidor del archivo a abrir */
		if ((numbytes = read(sock_client, buf, MAXDATASIZE)) == -1) {
			perror("error de lectura en el socket");
			exit(1);
		}
		recibidos += numbytes;
		fwrite(buf, 1, numbytes, fp);
	} while(numbytes == 1000);

	sprintf(buf, "GOT %d", recibidos);
	/* Envio de mensaje READY al servidor */
	if( write(sock_client, buf, strlen(buf)) == -1) {
		perror("Error en la escritura del socket");
		exit(1);
	}

	fclose(fp);

	return 0;
}
