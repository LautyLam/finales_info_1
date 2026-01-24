// constantes simbolicas
#define OK           0  // funcion terminada correctamente
#define EARGS       -1  // error en la cantdad de argumentos
#define EINFILE     -2  // error al abrir el archivo de entrada
#define EOUTFILE    -3  // error al abrir el archivo de salida

#define NCHANNELS   16

// definicion de la union para la lectura de datos
union logic_in {
    unsigned short int data;
    struct {
            unsigned int ch0  :1;
            unsigned int ch1  :1;
            unsigned int ch2  :1;
            unsigned int ch3  :1;
            unsigned int ch4  :1;
            unsigned int ch5  :1;
            unsigned int ch6  :1;
            unsigned int ch7  :1;
            unsigned int ch8  :1;
            unsigned int ch9  :1;
            unsigned int ch10 :1;
            unsigned int ch11 :1;
            unsigned int ch12 :1;
            unsigned int ch13 :1;
            unsigned int ch14 :1;
            unsigned int ch15 :1;
           } channel;
    };

// definicion de la union para la escritura de datos
union logic_out {
    unsigned char data;
    struct {
            unsigned int out0 :1;
            unsigned int out1 :1;
            unsigned int out2 :1;
            unsigned int out3 :1;
            unsigned int out4 :1;
            unsigned int out5 :1;
            unsigned int out6 :1;
            unsigned int out7 :1;
           } output;
    };

// prototipos de las finciones auxiliares
void process_data(union logic_in *din, union logic_out *dout);
void compute_zeroes(union logic_in *d, int counts[]);
void print_stats(int counts[], int total);
