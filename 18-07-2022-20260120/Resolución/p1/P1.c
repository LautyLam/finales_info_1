#include "mi_header.h"

int main(void)
{
	int cont,verificar,p;
	double *abscisas=NULL, *ordenadas=NULL, Xmin, Xmax;
	
    printf("Ingrese X minima\n");
    scanf("%lf",&Xmin);
    __fpurge(stdin);
    printf("Ingrese X maxima\n");
    scanf("%lf",&Xmax);
    __fpurge(stdin);

	printf("Ingrese cantidad de puntos\n");
    scanf("%i",&p);
    __fpurge(stdin);
      
    verificar=coseno(&abscisas,&ordenadas,Xmin,Xmax,p);
    
    for(cont=0;cont<verificar;cont++)
    {
		printf("%6.3lf,%6.3lf",abscisas[cont],ordenadas[cont]);
				if(cont<(verificar-1))
			printf(";");
	}
	
	free(abscisas);
	free(ordenadas);
    
	return(0);
}

int coseno(double **x,double **y, double Xm, double XM,int p)
{
	double resultado=0,factorial=1,binomio=1;
	int cont,i,j,k=1;
	double a, *abs, *ord;
	
	a=Xm;
	
	if(p<2)
		{return(-1);}		//minimo 2 puntos
	if(Xm>=XM)
		{return(-2);}		//el minimo es mayor al maximo
	if(x==NULL)
		{return(-3);}		//no me pasaron una direccion valida.
	
		
		*x=(double *)malloc(p*sizeof(double)); 	//x
		if(!(*x))
			return(-5);		//error de malloc
		*y=(double *)malloc(p*sizeof(double)); 	//x
		if(!(*y))
			return(-5);		//error de malloc
	abs=*x;		//para simplificar el uso de punteros y no usar (*x)[cont] o similar.
	ord=*y;		
	
	for(cont=0;cont<p;cont++)
	{
		abs[cont]=a;
		a+=(XM-Xm)/(p-1);		//mas delta x
	for(i=0;i<=TERMINOS;i++)
	{
		for(j=0;j<(2*i);j++)
			binomio*=(abs[cont]);
		for(j=0;j<(2*i);j++)
			factorial*=j+1;
		resultado+=(k*(binomio/factorial));
		binomio=1;
		factorial=1;
		k*=-1;
	}
	ord[cont]=resultado;
	resultado=0;
	k=1;
    }
	return p;
}

    
