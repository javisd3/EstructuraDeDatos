typedef struct ruta {
    tEstacion destino; 
    int tiempo;       
    struct ruta *sig;
} tRuta;

typedef tRuta *tListaRutas;

typedef struct estaciones {
    tEstacion info;
    tListaRutas rutas;
    struct estaciones *sig;
} tEstaciones;

typedef tEstaciones *tGrafo;

void añadirEstacion(tGrafo *g, char *nombre, char *linea, int accesible){
    tEstacion nuevaEstacion;
    crearEstacion(&nuevaEstacion, nombre, linea, accesible);

    tEstaciones *nuevoNodo = (tEstaciones *) malloc(sizeof(tEstaciones));

    asignarEstacion(&(nuevoNodo->info), nuevaEstacion);

    nuevoNodo->rutas = NULL;

    nuevoNodo->sig = *g;

    *g = nuevoNodo;
}

void conectarEstaciones(tGrafo *g, char *estacion1, char *estacion2, int tiempo){
    tEstaciones *aux = *g;
    tEstaciones *Origen = NULL;
    tEstaciones *Destino = NULL;

    while (aux != NULL && (Origen == NULL || Destino == NULL)){
        if (strcmp(obtenerNombre(aux->info), estacion1) == 0)){
            Origen = aux;
        }
        if (strcmp(obtenerNombre(aux->info), estacion2) == 0)){
            Destino = aux;
        }
        aux = aux->sig;
    }

    if (Origen == NULL || Destino == NULL){
        return;
    } else {
        tRuta *nuevaRuta = (tRuta *) malloc(sizeof(tRuta));
        asignarEstacion(&(nuevaRuta->destino, Origen->info));
        nuevaRuta->tiempo = tiempo;
        nuevaRuta->sig = Origen->rutas;
        Origen->rutas = nuevaRuta;

        tRuta *nuevaRuta = (tRuta *) malloc(sizeof(tRuta));
        asignarEstacion(&(nuevaRuta->destino, Destino->info));
        nuevaRuta->tiempo = tiempo;
        nuevaRuta->sig = Origen->rutas;
        Origen->rutas = nuevaRuta;
    }
}

void imprimirDestinosAccesibles(tGrafo g, char *origen){
    tEstaciones *aux = g;
    while (aux != NULL){
        strcmp(obtenerNombre(aux->info), origen) == 0){
            aux = origen;
            break;
        }
        aux = aux->sig;
    }

    if (aux == NULL){
        return;
    } else {

}
#include <stdio.h>
#include <string.h>

void imprimirDestinosAccesibles(tGrafo g, char *origen) {
    tEstaciones *aux = g; 
    while (aux != NULL) {
        if (strcmp(obtenerNombre(aux->info), origen) == 0) {
            tRuta *auxRuta = aux->rutas; 
            while (auxRuta != NULL) {
                if (auxRuta->destino.accesible == 1) {
                    printf("%s\n", obtenerNombre(auxRuta->destino));
                }
                auxRuta = auxRuta->sig; 
            }
            return; 
        }
        aux = aux->sig;
    }
}

void crearEstacion(tEstacion *destino, char *nombre, char *linea, int accesible);
void asignarEstacion(tEstacion *destino, tEstacion origen);
char* obtenerNombre(tEstacion est);
int iguales(tEstacion e1, tEstacion e2); /* Devuelve 1 si son la misma estación, 0 si no */

typedef struct {
    char *nombre;
    char *linea;
    int accesible;
} tEstacion;