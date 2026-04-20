typedef struct{
    tElemento info;
    int izq, der;
}tNodo

typedef struct {
    tNodo almacen[max];
    int raiz;
    int cabeceraLibres;
}tArbol;

