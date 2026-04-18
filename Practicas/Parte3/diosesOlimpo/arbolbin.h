#ifndef ARBOLBIN_H
#define ARBOLBIN_H

// Según el enunciado, de cada personaje almacenamos nombre y descripción
typedef struct {
    char nombre[50];
    char descripcion[200];
} tElemento;

typedef struct nodo {
    tElemento info;
    struct nodo *izq;
    struct nodo *der;
} tNodoArbol;

typedef tNodoArbol *tArbol;

void CrearArbolBinVacio(tArbol *a);
void ConstruirArbolB(tArbol *a, tArbol hi, tElemento e, tArbol hd);
int EsArbolVacio(tArbol a);
void HijoIzq(tArbol a, tArbol *hi);
void HijoDer(tArbol a, tArbol *hd);
void Raiz(tArbol a, tElemento *e);

#endif