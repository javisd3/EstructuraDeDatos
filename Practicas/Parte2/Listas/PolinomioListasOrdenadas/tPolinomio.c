#include <stdio.h>
#include <math.h> // Necesario para la función pow(base, exponente)
#include "tpolinomio.h"

tPolinomio leerPolinomio() {
    tPolinomio p;
    crearListaVacia(&p);
    int numTerminos;
    
    printf("¿Cuántos términos tiene el polinomio? ");
    scanf("%d", &numTerminos);
    
    for (int i = 0; i < numTerminos; i++) {
        tElemento e;
        leerElemento(&e); // Pedimos al usuario que introduzca coef y exp
        // Si el usuario mete un 0x^2, lo ignoramos porque matemáticamente es 0
        if (e.coeficiente != 0) {
            insertarOrdDecreciente(&p, e);
        }
    }
    return p; // Devolvemos el puntero al inicio de la lista
}

void mostrarPolinomio(tPolinomio p) {
    if (p == NULL) {
        printf("0\n"); // Si la lista está vacía, el polinomio es 0
        return;
    }
    tNodo *aux = p;
    // Recorremos la lista de principio a fin imprimiendo cada término
    while (aux != NULL) {
        mostrarElemento(aux->info);
        aux = aux->sig;
    }
    printf("\n");
}

// Pasamos 'pd' por referencia (puntero) para modificar el polinomio destino
void derivadaPolinomio(tPolinomio *pd, tPolinomio p) {
    crearListaVacia(pd); // Empezamos con una derivada vacía
    tNodo *aux = p;
    tElemento ed;
    
    while (aux != NULL) {
        // Derivamos el término actual
        derivadaElemento(&ed, aux->info);
        // Si al derivar no se hace 0 (ej. la derivada de una constante es 0), lo añadimos
        if (ed.coeficiente != 0) {
            insertarOrdDecreciente(pd, ed);
        }
        aux = aux->sig; // Pasamos al siguiente término
    }
}

// Evalúa el polinomio sustituyendo la 'x' por el valor dado
float valorPolinomio(tPolinomio p, float x) {
    float resultado = 0;
    tNodo *aux = p;
    while (aux != NULL) {
        // Calculamos: coeficiente * (x ^ exponente) y lo sumamos al total
        resultado += aux->info.coeficiente * pow(x, aux->info.exponente);
        aux = aux->sig;
    }
    return resultado;
}

// Suma p1 y p2, guardando el resultado en 's'
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2) {
    crearListaVacia(s);
    
    tNodo *aux = p1;
    // Insertamos todos los elementos del primer polinomio
    while (aux != NULL) {
        insertarOrdDecreciente(s, aux->info);
        aux = aux->sig;
    }
    
    // Insertamos los del segundo polinomio. 
    // Como nuestra función 'insertarOrdDecreciente' ya se encarga de sumar
    // los coeficientes si los exponentes son iguales, ¡la suma se hace sola!
    aux = p2;
    while (aux != NULL) {
        insertarOrdDecreciente(s, aux->info);
        aux = aux->sig;
    }
}

// Libera la memoria del polinomio usando la función de la lista subyacente
void destruirPolinomio(tPolinomio *p) {
    destruirLista(p);
}