#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

void inicializarHospital(tHospital *h) {
    for (int m = 0; m < 12; m++) {
        for (int d = 0; d < 31; d++) {
            crearColaPrioridad(&h->dias[m][d]);
        }
    }
}

// Ingresa al paciente en el día y mes correspondiente (restando 1 para usar como índice)
void ingresarPaciente(tHospital *h, tElemento e) {
    encolarPrioridad(&h->dias[e.fecha.mes - 1][e.fecha.dia - 1], e);
}

void inicializarListaDoble(tListaDoble *l) {
    l->primero = NULL;
    l->ultimo = NULL;
}

void inicializarEstudio(tEstudio *est) {
    inicializarListaDoble(&est->rango1);
    inicializarListaDoble(&est->rango2);
    inicializarListaDoble(&est->rango3);
    inicializarListaDoble(&est->rango4);
}

void insertarDoble(tListaDoble *l, tElemento e) {
    tNodoDoble *nuevo = (tNodoDoble *)malloc(sizeof(tNodoDoble));
    nuevo->info = e;
    nuevo->sig = NULL;
    nuevo->ant = l->ultimo;
    
    if (l->primero == NULL) {
        l->primero = nuevo;
    } else {
        l->ultimo->sig = nuevo;
    }
    l->ultimo = nuevo;
}

// Recorre todo el hospital y filtra a los graves
void generarEstudio(tHospital *h, tEstudio *est) {
    for (int m = 0; m < 12; m++) {
        for (int d = 0; d < 31; d++) {
            tNodoCola *act = h->dias[m][d].frente;
            while (act != NULL) {
                // Solo nos interesan ROJO y NARANJA [cite: 2731]
                if (act->info.prioridad == ROJO || act->info.prioridad == NARANJA) {
                    if (act->info.edad <= 15) insertarDoble(&est->rango1, act->info);
                    else if (act->info.edad <= 30) insertarDoble(&est->rango2, act->info);
                    else if (act->info.edad <= 50) insertarDoble(&est->rango3, act->info);
                    else insertarDoble(&est->rango4, act->info);
                }
                act = act->sig;
            }
        }
    }
}

void contarYMostrarLista(tListaDoble l, char *nombreRango) {
    int rojos = 0, naranjas = 0;
    tNodoDoble *act = l.primero;
    while (act != NULL) {
        if (act->info.prioridad == ROJO) rojos++;
        if (act->info.prioridad == NARANJA) naranjas++;
        act = act->sig;
    }
    printf("Rango %s -> Inmediata (Rojo): %d | Alta (Naranja): %d\n", nombreRango, rojos, naranjas);
}

void mostrarEstadisticas(tEstudio est) {
    printf("\n--- ESTADÍSTICAS DE URGENCIAS GRAVES ---\n");
    contarYMostrarLista(est.rango1, "0-15 años");
    contarYMostrarLista(est.rango2, "16-30 años");
    contarYMostrarLista(est.rango3, "31-50 años");
    contarYMostrarLista(est.rango4, "51+ años");
}

void borrarDeListaDoble(tListaDoble *l, int dia, int mes) {
    tNodoDoble *act = l->primero;
    while (act != NULL) {
        tNodoDoble *siguiente = act->sig;
        if (act->info.fecha.dia == dia && act->info.fecha.mes == mes) {
            if (act->ant != NULL) act->ant->sig = act->sig;
            else l->primero = act->sig;
            
            if (act->sig != NULL) act->sig->ant = act->ant;
            else l->ultimo = act->ant;
            
            free(act);
        }
        act = siguiente;
    }
}

// Borra los pacientes del 31 de Diciembre en ambas estructuras [cite: 2738]
void borrarUltimoDia(tHospital *h, tEstudio *est) {
    // 1. Borrar de la cola de prioridad (Mes 12, Día 31 -> índices 11 y 30)
    destruirColaPrioridad(&h->dias[11][30]);
    
    // 2. Borrar de las listas doblemente enlazadas
    borrarDeListaDoble(&est->rango1, 31, 12);
    borrarDeListaDoble(&est->rango2, 31, 12);
    borrarDeListaDoble(&est->rango3, 31, 12);
    borrarDeListaDoble(&est->rango4, 31, 12);
    printf("\nSe han borrado todos los registros del 31 de Diciembre.\n");
}