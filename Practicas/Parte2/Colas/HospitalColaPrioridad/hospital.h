#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "cola.h"

// Lista Dinámica Doblemente Enlazada para estadísticas
typedef struct nodoDoble {
    tElemento info;
    struct nodoDoble *sig;
    struct nodoDoble *ant;
} tNodoDoble;

typedef struct {
    tNodoDoble *primero;
    tNodoDoble *ultimo;
} tListaDoble;

// Estructura para el estudio estadístico (4 rangos de edad)
typedef struct {
    tListaDoble rango1; // 0-15
    tListaDoble rango2; // 16-30
    tListaDoble rango3; // 31-50
    tListaDoble rango4; // 51+
} tEstudio;

// Matriz del hospital: 12 meses, 31 días
typedef struct {
    tColaPrioridad dias[12][31];
} tHospital;

void inicializarHospital(tHospital *h);
void ingresarPaciente(tHospital *h, tElemento e);

void inicializarEstudio(tEstudio *est);
void generarEstudio(tHospital *h, tEstudio *est);
void mostrarEstadisticas(tEstudio est);

void borrarUltimoDia(tHospital *h, tEstudio *est);

#endif