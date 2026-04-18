#include <stdio.h>
#include <string.h>
#include "dioses.h"

// Función auxiliar para crear un tElemento rápidamente
tElemento crearElem(char *nombre, char *desc) {
    tElemento e;
    strcpy(e.nombre, nombre);
    strcpy(e.descripcion, desc);
    return e;
}

// 1. Construir el árbol de la figura
void crearArbolDioses(tArbol *arbol) {
    tArbol vacio;
    CrearArbolBinVacio(&vacio);
    
    // Nodos hoja (los que no tienen hijos)
    tArbol dedalo, orfeo, aristeo, hefeso, ares;
    ConstruirArbolB(&dedalo, vacio, crearElem("Dédalo", "Arquitecto y artesano legendario"), vacio);
    ConstruirArbolB(&orfeo, vacio, crearElem("Orfeo", "Músico y poeta legendario"), vacio);
    ConstruirArbolB(&aristeo, vacio, crearElem("Aristeo", "Semidiós asociado con la agricultura"), vacio);
    ConstruirArbolB(&hefeso, vacio, crearElem("Hefeso", "Dios de la forja y del fuego"), vacio);
    ConstruirArbolB(&ares, vacio, crearElem("Ares", "Dios de la guerra"), vacio);
    
    // Nivel intermedio inferior
    tArbol atenea, apolo;
    ConstruirArbolB(&atenea, dedalo, crearElem("Atenea", "Diosa de la civilización y sabiduría"), vacio);
    ConstruirArbolB(&apolo, orfeo, crearElem("Apolo", "Dios del sol"), aristeo);
    
    // Nivel intermedio superior
    tArbol zeus, hera;
    ConstruirArbolB(&zeus, atenea, crearElem("Zeus", "Dios supremo, líder de los 12"), apolo);
    ConstruirArbolB(&hera, hefeso, crearElem("Hera", "Diosa del matrimonio"), ares);
    
    // Raíz
    ConstruirArbolB(arbol, zeus, crearElem("Cronos", "Dios del tiempo"), hera);
}

// 2. Método que dado un nombre dice si existe
int existeDios(tArbol a, char *nombre) {
    tElemento r;
    tArbol hi, hd;
    
    if(EsArbolVacio(a)) {
        return 0; // No está
    } else {
        Raiz(a, &r);
        // Usamos strcmp para comparar cadenas (devuelve 0 si son iguales)
        if(strcmp(r.nombre, nombre) == 0) {
            return 1; // Lo encontramos en la raíz actual
        } else {
            HijoIzq(a, &hi);
            HijoDer(a, &hd);
            // Buscamos en la izquierda O en la derecha
            return existeDios(hi, nombre) || existeDios(hd, nombre);
        }
    }
}

// 3. Método para saber si el primero es padre del segundo
int esPadre(tArbol a, char *padre, char *hijo) {
    tElemento r, rIzq, rDer;
    tArbol hi, hd;
    
    if(EsArbolVacio(a)) {
        return 0;
    } else {
        Raiz(a, &r);
        HijoIzq(a, &hi);
        HijoDer(a, &hd);
        
        // Si el nodo actual es el padre que buscamos...
        if(strcmp(r.nombre, padre) == 0) {
            // Comprobamos si su hijo izquierdo se llama como el hijo que buscamos
            if(!EsArbolVacio(hi)) {
                Raiz(hi, &rIzq);
                if(strcmp(rIzq.nombre, hijo) == 0) return 1;
            }
            // Comprobamos si su hijo derecho se llama como el hijo que buscamos
            if(!EsArbolVacio(hd)) {
                Raiz(hd, &rDer);
                if(strcmp(rDer.nombre, hijo) == 0) return 1;
            }
            return 0; // Encontramos al padre, pero ese no es su hijo
        }
        
        // Si no es el padre, seguimos buscando al padre por las ramas
        return esPadre(hi, padre, hijo) || esPadre(hd, padre, hijo);
    }
}

// 4. Imprimir en preorden (Raíz, Izquierda, Derecha)
void imprimirPreorden(tArbol a) {
    tElemento r;
    tArbol hi, hd;
    
    if(!EsArbolVacio(a)) {
        Raiz(a, &r);
        // Primero imprimimos la raíz (con formato amigable)
        printf("%s, ", r.nombre);
        
        // Luego extraemos los hijos y hacemos la llamada recursiva
        HijoIzq(a, &hi);
        HijoDer(a, &hd);
        imprimirPreorden(hi);
        imprimirPreorden(hd);
    }
}