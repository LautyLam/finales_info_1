#include <stdio.h>
#include <time.h> //uso time()
#include <stdlib.h> //uso malloc() y rand()
//info1 misaelcudek@gmail.com

struct port
{
unsigned char p0:1;
unsigned char p1:1;
unsigned char p2:1;
unsigned char p3:1;
unsigned char p4:1;
unsigned char p5:1;
unsigned char p6:1;
unsigned char p7:1;
};

struct paquete
{
unsigned char MACori[6];
unsigned char MACdes[6];
struct port entrada;
struct port salida;
};

void rellenarArray(struct paquete **);
void cargarArray(struct paquete **);
void mostrarArray(struct paquete **);
void liberar(struct paquete **);
void printMAC(char *);
void printPuerto(struct port);
#define TAM 10

int main()

{
    struct paquete * array[TAM];


    rellenarArray(array);
    cargarArray(array);
    mostrarArray(array);
    liberar(array);
}

void rellenarArray(struct paquete ** p)
{
    for(int i=0;i<TAM;i++)
    {
    p[i]=(struct paquete *)malloc(sizeof(struct paquete));
    if(p[i]==NULL)
        {
           printf("Error de malloc\n");
           exit(1);//cierro el programa no hay memoria.
        }
    }
}
void cargarArray(struct paquete ** p)
{
    srand(time(NULL));
    for(int i=0;i<TAM;i++)
    {
        p[i]->entrada.p0=0;
        p[i]->entrada.p1=0;
        p[i]->entrada.p2=0;
        p[i]->entrada.p3=0;
        p[i]->entrada.p4=0;
        p[i]->entrada.p5=0;
        p[i]->entrada.p6=0;
        p[i]->entrada.p7=0;

        p[i]->salida.p0=0;
        p[i]->salida.p1=0;
        p[i]->salida.p2=0;
        p[i]->salida.p3=0;
        p[i]->salida.p4=0;
        p[i]->salida.p5=0;
        p[i]->salida.p6=0;
        p[i]->salida.p7=0;

         switch(rand()%8)
         {
        case 0: p[i]->entrada.p0=1; break;
        case 1: p[i]->entrada.p1=1; break;
        case 2: p[i]->entrada.p2=1; break;
        case 3: p[i]->entrada.p3=1; break;
        case 4: p[i]->entrada.p4=1; break;
        case 5: p[i]->entrada.p5=1; break;
        case 6: p[i]->entrada.p6=1; break;
        case 7: p[i]->entrada.p7=1; break;
        }

        switch(rand()%8)
         {
        case 0: p[i]->salida.p0=1; break;
        case 1: p[i]->salida.p1=1; break;
        case 2: p[i]->salida.p2=1; break;
        case 3: p[i]->salida.p3=1; break;
        case 4: p[i]->salida.p4=1; break;
        case 5: p[i]->salida.p5=1; break;
        case 6: p[i]->salida.p6=1; break;
        case 7: p[i]->salida.p7=1; break;
        }

        for(int j=0;j<6;j++)
        {
         p[i]->MACori[j]=(unsigned char)(rand()%256);
         p[i]->MACdes[j]=(unsigned char)(rand()%256);
        }

    }
}

void mostrarArray(struct paquete ** p)
{
    printf("MAC destino\t\tMAC origen\t\tPuerto destino\tPuerto origen\n");
     for(int i=0;i<TAM;i++)
    {
    printMAC(p[i]->MACdes);
    printf("\t");
    printMAC(p[i]->MACori);
    printf("\t");
    printPuerto(p[i]->entrada);
    printf("\t");
    printPuerto(p[i]->salida);
    printf("\n");
    }
}

void printMAC(char * mac)
{
    for(int i=0;i<6;i++)
    {
        printf("%02x",(unsigned char)mac[i]);
        if(i!=5)
        {
            printf(":");
        }
    }
}

void printPuerto(struct port p)
{
    printf("%c",p.p0 ? '1':'0');
    printf("%c",p.p1 ? '1':'0');
    printf("%c",p.p2 ? '1':'0');
    printf("%c",p.p3 ? '1':'0');
    printf("%c",p.p4 ? '1':'0');
    printf("%c",p.p5 ? '1':'0');
    printf("%c",p.p6 ? '1':'0');
    printf("%c",p.p7 ? '1':'0');
}

void liberar(struct paquete ** p)
{
     for(int i=0;i<TAM;i++)
    {
    free(p[i]);
    p[i]=NULL;
    }
}


