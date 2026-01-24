

struct hijos
{
	int pid; 			//Número del proceso hijo generado.
	char * archivo; 	//Nombre del archivo que utiliza dicho proceso.
	int nro_arg;		//Número de orden en el que fue cargado el nombre en la línea de comando.
};


int convertir (int *, int, char *);
int nvo_nombre (char *, char *);
int lectura (char *, int **);
int f_hijo (char * );

#define OK 0
#define ERROR 1
#define ERR_LEC -1
#define DECRYPT 8
#define DESPLAZ 8
#define UNBYTE 256

