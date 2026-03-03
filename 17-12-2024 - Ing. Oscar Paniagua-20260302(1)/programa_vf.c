// compilar:    gcc -Wall programa_vf.c -o programa
// ejecutar:    ./programa -f rmc.txt

#include <stdio.h>
#include <stdlib.h>  // strtol
#include <string.h>

#define TRAMA_OK 0
#define TRAMA_ERROR 1
#define BUFFER_SIZE 1024

int calcular_crc(char *p);
int obtener_crc(char *p);
int validar(char *p);

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    char filename[256];
    FILE *fp;
    int resultado;

    // Verificar cantidad de argumentos
    if (argc < 3) {
        printf("Uso: %s -f <archivo>\n", argv[0]);
        return 1;
    }

    // procesar los argumentos
    if (strcmp(argv[1], "-f") == 0) {  // comprobar si el primer argumento es "-f"
        strcpy(filename, argv[2]);     // el siguiente argumento es el nombre del archivo

    } else {
        printf("Uso: %s -f <archivo>\n", argv[0]);
        return 1;
    }

    // abro el archivo de taxto con las tramas
    fp = fopen(filename, "r");

    if (fp == NULL) {
        // Si no se pudo abrir el archivo, muestra un mensaje de error
        perror("Error al abrir el archivo");
        return 1;
    }

    // leer el archivo línea por línea
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Eliminar el salto de línea si está presente
        buffer[strcspn(buffer, "\n")] = '\0';

        // proceso solo las tramas que tienen el estado 'A'
        resultado = validar(buffer);
        if (resultado == TRAMA_OK) {
            printf("Trama: %s - Checksum Válido\n", buffer);
        } else {
            printf("Trama: %s - Checksum Inválido\n", buffer);
        }
    }

    // Cierra el archivo
    fclose(fp);

    return 0;
}

/**
 * función que calcula y devuelve el CRC
 * el CRC se calculo desde el $ al *
 */
int calcular_crc(char *p) {
    char crc = 0;

    // saltar el '$' para calcular el CRC, ya que no se incluye en el calculo
    p++;

    while (*p && *p != '*') {
        crc ^= *p;  // operador XOR
        p++;
    }
    return crc;
}

/**
 * función que obtiene y devuelve el CRC
 */
int obtener_crc(char *p) {
    // el "crc" se encuentra en las dos ultimas posiciones del string
    // despues del asterisco '*'
    while (*p != '*' && p != NULL) {
        p++;
    }
    p++;
    return (int)strtol(p, NULL, 16);
}

/**
 * función que valida la trama
 * comprando el CRC que viene en la trama
 * con el CRC que se calcula
 * devuelve:
 *  TRAMA_OK: en el caso que ambos CRC coincidan
 *  TRAMA_ERROR: en el caso que ambos CRC no coincidan
 */
int validar(char *p) {
    int crc_calculado;
    int crc_leido;

    crc_leido = obtener_crc(p);
    crc_calculado = calcular_crc(p);

    if (crc_calculado == crc_leido)
        return TRAMA_OK;
    return TRAMA_ERROR;
}
