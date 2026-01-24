// Final 24/05/2023
// Propuesta de resolución punto 2
// main()
// Ing. Daniel Pellettieri

#include "p2.h"

int main(void)
{
    char pila[TAM_P], exp[TAM_EXP]={"((3x+5(4x-3)+4y)(4+6x)^2+(3x(5y-18)))"};
    char pp=0, i;

    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
        {
            if(apilar(pila, &pp, '(')==1)
            {
                printf("\nDesborde de pila");
                return 0;
            }
        }
        if(exp[i]==')')
        {
            if(desapilar(pila, &pp)==1)
            {
                 printf("\nError en parentesis");
                 printf("\n\n");
                 return 0;
            }
        }
    }

    if(vacia(pila, &pp)==1)
        printf("\nParentesis balanceados");
    else
        printf("\nError en parentesis");

    printf("\n\n");
    return 0;
}




