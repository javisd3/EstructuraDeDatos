#ifndef FECHA_H
#define FECHA_H

typedef struct {
    int dia;
    int mes;
    int anio;
} tFecha;

// Declaración de funciones básicas para la fecha
void crearFecha(tFecha *f, int d, int m, int a);
void mostrarFecha(tFecha f);
int igualFecha(tFecha f1, tFecha f2);

#endif // FECHA_H