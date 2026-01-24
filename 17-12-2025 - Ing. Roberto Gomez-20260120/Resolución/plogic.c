#include <stdio.h>
#include "func_plogic.h"

int main(int ac, char **av) {
    FILE *fpi, *fpo;
    union logic_in data_in;
    union logic_out data_out;
    int total_count = 0;
    int input_count[NCHANNELS] = {0};

    // verificacionde la cantidad de argumentos
    if (ac != 3){
        printf("Error al invocar %s\n", av[0]);
        return EARGS;
    }
    // abro el archivo de entrada de datos
    if ((fpi = fopen(av[1], "r")) == NULL){
        printf("Error al abrir el archivo de entrada '%s'\n", av[1]);
        return EINFILE;
    }
    // abro el archivo de salida de datos
    if ((fpo = fopen(av[2], "w")) == NULL){
        fclose(fpi);
        printf("Error al abrir el archivo de salida '%s'\n", av[2]);
        return EOUTFILE;
    }

    while(1){
        // leo un dato del archivo de entrada
        fread(&(data_in.data), sizeof(data_in.data), 1, fpi);
        if(feof(fpi))
            break;
        // proceso el dato
        process_data(&data_in, &data_out);

        // computo los unos
        compute_zeroes(&data_in, input_count);

        // incremento el contador total;
        total_count++;

        // escribo el dato procesado en el archivo de salida
        fwrite(&(data_out.data), sizeof(data_out.data), 1, fpo);

    }
    // imprimo los porcentajes de unos de cada entrada
    print_stats(input_count, total_count);

    // cierro los archivos
    fclose(fpi);
    fclose(fpo);
    return OK;
}
