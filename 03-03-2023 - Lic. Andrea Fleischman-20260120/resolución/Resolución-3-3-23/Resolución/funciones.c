#include "funciones.h"

int crearListado(LISTAENERGIA **listado, FILE *fp,unsigned int barrio_filtro)
{
	ENERGIA cliente_aux;
	unsigned int barrio_cliente;
	LISTAENERGIA * nodo_nuevo;

	while(!feof(fp))
	{	if(!obtenerRegistro(fp,&cliente_aux))
		{	printf("[DEBUG] Obtener Registro: DATO LEIDO CORRECTAMENTE\n");
			obtenerBarrio(cliente_aux.codigoCliente, &barrio_cliente);
			
			if (barrio_cliente == barrio_filtro)
			{	/*--------------------------------------------------------*/
				// Creo nuevo nodo
				nodo_nuevo = (LISTAENERGIA *)malloc(sizeof(LISTAENERGIA));	
				// Asigno datos leidos del archivo al nuevo nodo
				nodo_nuevo->cliente = cliente_aux;
				// Agrego el nodo al principio de la lista
				nodo_nuevo->siguiente = *listado;
				*listado = nodo_nuevo;
				printf("[DEBUG] Nuevo Nodo : [%s]\n", nodo_nuevo->cliente.nombreyapellido);
				/*--------------------------------------------------------*/
			}
			// Barrio no deseado. No lo agrego a la lista. 
			// Seguir loopeando en el archivo
		}
	}
	printf("[DEBUG] No hay mas datos en el archivo...\n");
	return 0;
}
/*============================================================================*/
/*============================================================================*/
int obtenerRegistro(FILE *fp,ENERGIA *cliente)
{
	if(fread((ENERGIA*)cliente,sizeof(ENERGIA),1,fp))
	{	return 0;
	}
	else
	{	return 1;
	}
}
/*============================================================================*/
/*============================================================================*/
int obtenerBarrio(unsigned int codigoCliente, unsigned int *barrio_cliente)
{
	unsigned int aux;
	aux = codigoCliente;
	printf("[DEBUG] Barrio - aux = [%d] = [0x%0X]\n",aux,aux);
	aux = aux & 0x0000000F;
	printf("[DEBUG] Barrio - aux = [%d] = [0x%0X]\n",aux,aux);
	*barrio_cliente = aux; 
	return 0;
}
/*============================================================================*/
/*============================================================================*/
