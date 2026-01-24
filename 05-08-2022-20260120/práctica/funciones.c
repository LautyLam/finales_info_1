#include "funciones.h"

int encriptar (const char * src, char * dst)
{
    char aux [MAX];
    int numero;
    numero = desplazar_letras (src,aux);
    encriptar_numeros (aux,dst);
    return numero;    
}

int desplazar_letras (const char * src, char * dst)
{  
    int len,i,desplazamiento;
    len = strlen (src);
    desplazamiento = aleatorio (1,24); 
    
    for (i=0;i<len;i++)
    {
        if (src[i]>= 'A' && src[i] <='Z')
        {
            dst[i] = src[i] + desplazamiento; 
            
            if (dst [i] >'Z')
                dst[i] = dst [i] - 'Z' + 'A' -1;           
        }
        else
            dst [i] = src [i];       
    }
    
    dst [i] = '\0';
    
    return desplazamiento;
    
}


int aleatorio (int base, int rango)
{
    return ( random() % rango ) + base;
}


void string_reverse (char * str)
{
    int len,i;
    char aux;
    len = strlen (str);
    for (i=0;i<len/2;i++)
    {
        aux = str [i];
        str [i] = str [len -i - 1];
        str [len -i - 1] = aux;
    }
}

void octal (int numero, char * str)
{
    int i=0;
    while (numero)
    {
        str[i]= numero % 8 + '0';
        numero = numero /8;
        i++;
    }
    str [i] = '\0';
    string_reverse (str);  
}

void encriptar_numeros (const char * src, char * dst)
{
    
    int len,i,j,k,posicion =0,numero,flag_conversion=0;
    len = strlen (src);
    len++;
    char aux [MAX]; 
    for (i=0,j=0;i<len;i++)
    {
        if (src[i]>= '0' && src[i] <='9')
        {
            aux [posicion] = src [i];
            posicion ++;
            flag_conversion=1;
        }

        else
        {
            if (flag_conversion)
            {
                
                aux [posicion] = '\0';
                posicion = 0;
                
                numero = atoi (aux);
                flag_conversion = 0;
                
                octal (numero,aux); 
                for (k=0;k<strlen (aux);k++)
                {
                    switch (aux [k])
                    {
                        case '0':
                            aux [k] = '$';
                            break;
                    
                        case '1':
                            aux [k] = '%';
                            break;
                    
                        case '2':
                            aux [k] = '&';
                            break;
                    
                        case '3':
                            aux [k] = '*';
                            break;
                    
                        case '4':
                            aux [k] = '@';
                            break;
                    
                        case '5':
                            aux [k] = '!';
                            break;
                    
                        case '6':
                            aux [k] = '+';
                            break;
                    
                        case '7':
                            aux [k] = '=';
                            break;
                    
                        default:
                            break;
                    }
                }

               
                strcpy (&dst[j],aux);
                j += strlen (aux)+1;
                dst [j] = src [i];       
                j++;
            }
            else
            {
                dst [j] = src [i];       
                j++;
                
            }
        }
            
            
    }   
    
    dst [j] = '\0';
    
   
}



