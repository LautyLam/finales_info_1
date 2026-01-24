#include <stdio.h>
#include "func_plogic.h"


// funcion que procesa un dato de entrada y arma el dato de salida
void process_data(union logic_in *din, union logic_out *dout){
    dout->data = 0;

    // usando comparacion entre bits
    dout->output.out0 = (din->channel.ch0 == din->channel.ch1) && (din->channel.ch0 == din->channel.ch2) && (din->channel.ch0 == din->channel.ch3);
    dout->output.out1 = (din->channel.ch4 == din->channel.ch5) && (din->channel.ch4 == din->channel.ch6) && (din->channel.ch4 == din->channel.ch7);
    dout->output.out2 = (din->channel.ch8 == din->channel.ch9) && (din->channel.ch8 == din->channel.ch10) && (din->channel.ch8 == din->channel.ch11);
    dout->output.out3 = (din->channel.ch12 == din->channel.ch13) && (din->channel.ch12 == din->channel.ch14) && (din->channel.ch12 == din->channel.ch15);
    dout->output.out4 =  !(din->channel.ch0 | din->channel.ch1 | din->channel.ch2 | din->channel.ch3);
    dout->output.out5 =  !(din->channel.ch4 | din->channel.ch5 | din->channel.ch6 | din->channel.ch7);
    dout->output.out6 =  !(din->channel.ch8 | din->channel.ch9 | din->channel.ch10 | din->channel.ch11);
    dout->output.out7 =  !(din->channel.ch12 | din->channel.ch13 | din->channel.ch14 | din->channel.ch15);

    // usando una mascara
    // unsigned int m = 0x00f;
    // dout->output.out0 = (din->data & m) == m || (din->data & m) == 0; 
    // dout->output.out4 = (din->data & m) == 0;
    // m <<= 4;
    // dout->output.out1 = (din->data & m) == m || (din->data & m) == 0; 
    // dout->output.out5 = (din->data & m) == 0;
    // m <<= 4;
    // dout->output.out2 = (din->data & m) == m || (din->data & m) == 0; 
    // dout->output.out6 = (din->data & m) == 0;
    // m <<= 4;
    // dout->output.out3 = (din->data & m) == m || (din->data & m) == 0; 
    // dout->output.out7 = (din->data & m) == 0;
}

// funcion que computa que entradas estan en uno
void compute_zeroes(union logic_in *d, int counts[]){
    // usando los bit del campo channel de la union
    if (!d->channel.ch0)
        counts[0]++;
    if (!d->channel.ch1)
        counts[1]++;
    if (!d->channel.ch2)
        counts[2]++;
    if (!d->channel.ch3)
        counts[3]++;
    if (!d->channel.ch4)
        counts[4]++;
    if (!d->channel.ch5)
        counts[5]++;
    if (!d->channel.ch6)
        counts[6]++;
    if (!d->channel.ch7)
        counts[7]++;
    if (!d->channel.ch8)
        counts[8]++;
    if (!d->channel.ch9)
        counts[9]++;
    if (!d->channel.ch10)
        counts[10]++;
    if (!d->channel.ch11)
        counts[11]++;
    if (!d->channel.ch12)
        counts[12]++;
    if (!d->channel.ch13)
        counts[13]++;
    if (!d->channel.ch14)
        counts[14]++;
    if (!d->channel.ch15)
        counts[15]++;
    // usando el campo data de la union
    // int i;
    // for (i=0; i<NCHANNELS; i++) {
    //     if (!((d->data >> i) & 1)) {
    //         counts[i]++;
    //     }
    // }
}

// funcion que imprime en pantalla el porcentaje de unos en cada entrada
void print_stats(int counts[], int total){
    int n;
    for(n=0; n<NCHANNELS; n++)
        printf("Channel #%d\t%.2f%%\n", n, ((float)(total - counts[n]) / total) * 100.0);
}
