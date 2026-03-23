#include <stdio.h>
#include "Fecha.h"

void crearFecha(tFecha *f, int d, int m, int a) {
    f->dia = d;
    f->mes = m;
    f->anio = a;
}

void mostrarFecha(tFecha f) {
    printf("%02d/%02d/%04d", f.dia, f.mes, f.anio);
}

int igualFecha(tFecha f1, tFecha f2) {
    return (f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio);
}