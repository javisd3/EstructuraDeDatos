#include <stdio.h>
#include "telemento.h"

// Copia los valores de e2 dentro de la variable apuntada por e1.
void asignarElemento(tElemento *e1, tElemento e2) {
    e1->coeficiente = e2.coeficiente;
    e1->exponente = e2.exponente;
}

// Pasamos el elemento por referencia (puntero) porque scanf necesita modificarlo.
void leerElemento(tElemento *e) {
    printf("Introduce coeficiente y exponente separados por espacio: ");
    scanf("%f %d", &e->coeficiente, &e->exponente);
}

// Dos términos son "iguales" en este contexto si tienen el mismo exponente
// (esto nos servirá para saber si debemos sumar sus coeficientes).
int igualElemento(tElemento uno, tElemento dos) {
    return (uno.exponente == dos.exponente);
}

// Un término es "mayor" que otro si su exponente es mayor.
// Esto sirve para mantener la lista ordenada de forma decreciente.
int mayor(tElemento uno, tElemento dos) {
    return (uno.exponente > dos.exponente);
}

// Imprime el término con un formato amigable.
void mostrarElemento(tElemento t) {
    // Si el coeficiente es positivo, le ponemos un '+' delante para que quede bien (ej. +3.00x^2)
    if (t.coeficiente > 0) printf("+");
    printf("%.2fx^%d ", t.coeficiente, t.exponente);
}

int getExponente(tElemento e) { return e.exponente; }
float getCoeficiente(tElemento e) { return e.coeficiente; }

// Calcula la derivada matemática de un monomio: nx^(n-1)
void derivadaElemento(tElemento *ed, tElemento e) {
    ed->coeficiente = e.coeficiente * e.exponente;
    ed->exponente = e.exponente - 1;
}