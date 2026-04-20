typedef struct Nodo{
    tElemento info;
    struct Nodo *hijo;
    struct Nodo *hermano;
}tNodo;

typedef tNodo *tArbol;