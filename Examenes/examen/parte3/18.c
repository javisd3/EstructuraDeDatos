#include <stdlib.h>

// 1. Estructura para las aristas (Rutas)
typedef struct nodoRuta {
    tPlaneta destino;           // Planeta al que llega la ruta
    int distancia;              // Dato extra: años luz
    int riesgo;                 // Dato extra: nivel de peligro [1-10]
    struct nodoRuta *sig;       // Puntero a la siguiente ruta desde el mismo origen
} tNodoRuta;

typedef tNodoRuta *tListaRutas;

// 2. Estructura para los vértices (Planetas)
typedef struct nodoPlaneta {
    tPlaneta info;              // Datos del planeta (TAD)
    tListaRutas rutas;          // Sub-lista de adyacencia (rutas que SALEN de aquí)
    struct nodoPlaneta *sig;    // Puntero al siguiente planeta de la galaxia
} tNodoPlaneta;

// 3. Puntero de acceso al grafo principal
typedef tNodoPlaneta *tRedGalactica;

void crearRuta(tRedGalactica *g, tPlaneta origen, tPlaneta destino, int dist, int riesgo){

tNodoPlaneta *aux = *g;                           //inicio nodo vacios
tNodoPlaneta *nodoOrigen = NULL;
tNodoPlaneta *nodoDestino = NULL;

while(aux != NULL && (nodoOrigen == NULL || nodoDestino == NULL){
    if(iguales(aux->info, origen) == 1){
        nodoOrigen = aux;                            //anclo al grafo
    }
    if(iguales(aux->info, destino) == 1){
        nodoDestino = aux;
    }
    aux = aux->sig;
}

if (nodoOrigen == NULL || nodoDestino == NULL){        // si no esta vacio 
    return;
}

tNodoRuta *nuevaRuta = (tNodoRuta*)malloc(sizeof(tNodoRuta));      //reservo espacio

asignarPlaneta(&(nuevaRuta->destino),nodoDestino->info);           //  asigno a la listaAdy el planeta de 
                                                                    // destino
nuevaRuta->distancia = dist;
nuevaRuta->riesgo = riesgo;                                        //inicio datos

nuevaRuta->sig = nodoOrigen->rutas;                           //añado la ruta al nodo principal del origen
nodoOrigen->rutas = nuevaRuta;
}
