

typedef struct{
    char titulo[MAX_TITULO];
    tFecha fecha;
    char medio[100];
    int visitas;

}tElemento

void crearNoticia(tElemento *n, char t[100], tFecha f, char m, int num);