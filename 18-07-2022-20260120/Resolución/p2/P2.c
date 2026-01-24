#include "mi_header.h"


int main(int argc, char *argv[])
{
	int a,fd, listado['z'-'a'+1],i;
	
	fd=open(argv[1],O_RDWR | O_CREAT,S_IRUSR|S_IWUSR);
	
	for(i=0;i<'z'-'a';i++)
		listado[i]=0;
	a=contador(fd,listado);
	if(a<0)
	{
		printf("error: %d\n",a);
		return 0;
	}
	
	for(i=0;i<'z'-'a';i++)
		printf("%c:%i veces\n",'a'+i,listado[i]);			
	return 0 ;
}

int contador(int archivo, int *vector)
{
	int cont;
	char letra;
	
	if(!vector)
		return -1;
	if(!archivo)
		return -2;	
	
	do
	{
		cont=read(archivo,&letra,1);
		if(cont)
		{
			if(letra>='a' && letra<='z')
				{
					vector[letra-'a']++;
				}
			if(letra>='A' && letra<='Z')
				vector[letra-'A']++;
		}
	}while(cont);	
	return(0);
}
