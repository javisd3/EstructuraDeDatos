// Estructura para la lista de adyacencia (las rutas que salen de un aeropuerto)
typedef struct NodoRuta {
    tAeropuerto destino;    // El aeropuerto al que LLEGA este vuelo
    int numVuelo;           // Dato extra: número del vuelo
    int distancia;          // Dato extra: distancia en km
    struct NodoRuta *sig;   // Puntero a la siguiente ruta desde el mismo origen
} tNodoRuta;

typedef tNodoRuta *tListaRutas; // Alias para la sub-lista de conexiones

// Estructura para los vértices (la lista principal de aeropuertos del sistema)
typedef struct NodoAeropuerto {
    tAeropuerto info;               // Datos del aeropuerto (IATA, ciudad, pistas)
    tListaRutas rutas_salientes;    // ¡AQUÍ ESTÁ LA CLAVE! Su lista de adyacencia
    struct NodoAeropuerto *sig;     // Puntero al siguiente aeropuerto en el sistema
} tNodoAeropuerto;

// El Grafo es un puntero al primer aeropuerto de nuestra lista principal
typedef tNodoAeropuerto *tGrafo;

#include <stdlib.h>

void registrarAeropuerto(tGrafo *g, char *iata, char *ciudad, int pistas) {
    
    // 1. Preparamos el "paquete" de datos usando el TAD proporcionado
    tAeropuerto nuevoAero;
    crearAeropuerto(&nuevoAero, iata, ciudad, pistas);

    // 2. Fabricamos el nuevo "nodo" (vértice) que vivirá en nuestro grafo
    tNodoAeropuerto *nuevoNodo = (tNodoAeropuerto *) malloc(sizeof(tNodoAeropuerto));

    // 3. Rellenamos el nodo con la información
    // Usamos asignarAeropuerto porque es la herramienta oficial del TAD
    asignarAeropuerto(&(nuevoNodo->info), nuevoAero);
    
    // El enunciado manda: inicialmente NO tiene rutas
    nuevoNodo->rutas_salientes = NULL; 

    // 4. Lo enganchamos al principio de nuestra red de aeropuertos
    // El "siguiente" de nuestro nuevo nodo será el antiguo primer nodo
    nuevoNodo->sig = *g;
    
    // Actualizamos la puerta de entrada del grafo
    *g = nuevoNodo;
}


void crearRuta(tGrafo *g, char *iataOrigen, char *iataDestino, int numVuelo, int distancia){
    tNodoAeropuerto *aux = *g;
    tNodoAeropuerto *Origen = NULL;
    tNodoAeropuerto *Destino = NULL;

    // 1. Buscamos los aeropuertos MIENTRAS no hayamos llegado al final y nos falte alguno
    while (aux != NULL && (Origen == NULL || Destino == NULL)){
        
        if (strcmp(obtenerIATA(aux->info), iataOrigen) == 0){
            Origen = aux;
        }
        
        if (strcmp(obtenerIATA(aux->info), iataDestino) == 0){
            Destino = aux;
        }
        
        aux = aux->sig;
    }

    // 2. Si alguno de los dos no existe, salimos sin hacer nada (usando ==)
    if (Origen == NULL || Destino == NULL){
        return;
    } else {
        // 3. Creamos la arista
        tNodoRuta *nuevaRuta = (tNodoRuta *) malloc(sizeof(tNodoRuta));
        
        // Usamos la función del TAD para meter todos los datos del aeropuerto destino
        asignarAeropuerto(&(nuevaRuta->destino), Destino->info);
        
        nuevaRuta->numVuelo = numVuelo;
        nuevaRuta->distancia = distancia;
        
        // 4. Conectamos la arista SOLO en la lista del Origen (Grafo dirigido)
        nuevaRuta->sig = Origen->rutas_salientes;
        Origen->rutas_salientes = nuevaRuta;
    }
}