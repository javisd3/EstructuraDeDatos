#include <stdio.h>
#include "elemento.h"

void mostrarElemento(tElemento e) {
    printf("%d ", e);
}

int igualElemento(tElemento e1, tElemento e2) {
    return e1 == e2;
}

int menorElemento(tElemento e1, tElemento e2) {
    return e1 < e2;
}