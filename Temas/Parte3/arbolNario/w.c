//como hijo-hermano
typedef struct Nodo{
    tElemento info;
    struct Nodo *hijo;
    struct Nodo *hermano;
}tNodo;

typedef tNodo *tArbol;

//como lista de hijos
typedef struct nodo{
    struct Nodo *ref;;
    struct Hijo *sig;
}tHijo;

typedef struct Nodo{
    tElemento info;
    tHijo *tListaHijos;
}tNodo;

typedef tNodo *tArbol;