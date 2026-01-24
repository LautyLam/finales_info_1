#include funciones.h

int main(int argc, char *argv[])
{
	FILE *id;
	ENERGIA *cliente;
	LISTAENERGIA *lista=NULL;
	
	unsigned int barrio=0;
	
	
	obtenerBarrio(25000,&barrio);

	if (argc == 2)
	{
		id = fopen(argv[1],"r");
		if (id)
		{	crearListado(&lista,id,BARRIO_FILTRO);
			fclose(id);		
		}
		else
		{	printf("main(): No se puede abrir el archivo\n");
			return 2;		
		}
	}
	else
	{	printf("main(): La cantidad de argumentos es incorrecta\n");
		return 1;		
	}
	return 0;
}
