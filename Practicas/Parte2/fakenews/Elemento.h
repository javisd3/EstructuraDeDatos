//lista con puntero a cabecera al final o lista circular

typedef struct{
    char titulo[MAX_TITULO];
    tFecha fecha;
    char medio[MAX_MEDIO];
    int visitas;

}tElemento

void crearNoticia(tElemento *n, char t[100], tFecha f, char m[10], int num);
void asignarElemento(tElemento *n1, tElemento n2);
int igualElemento(tElemento n1, tElemento n2);
void mostrarElemento(tElemento n);

int getVisitas(tElemento n);