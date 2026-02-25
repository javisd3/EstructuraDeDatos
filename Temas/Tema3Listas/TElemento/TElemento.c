#include <stdio.h>
#include "TElemento.h"

void asignarElemento(tElemento *e1, tElemento *e2)
{
    *e1 = e2;
}

void crearElemento(int num, tElemento *e)
{
    *e = num;
}

int igualElemento(tElemento uno, tElemento dos)
{
    return uno == dos;
}

void mostrarElemento(tElemento t)
{
    printf("%d", t);
}