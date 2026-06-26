// 1. Estructura para las aristas (Portales)
typedef struct listaAdy {
    tMundo destino;
    int Energia;
    int llave;
    struct listaAdy *sig;
} tlistaAdy;                 // CORRECCIÓN: Falta el punto y coma
typedef tlistaAdy *ListaAdyacencia;

// 2. Estructura para los vértices (Mundos)
typedef struct nodo {
    tMundo info;
    ListaAdyacencia portales; // CORRECCIÓN CRÍTICA: ¡Faltaba la sub-lista de conexiones!
    struct nodo *sig;
} tNodo;                     // CORRECCIÓN: Falta el punto y coma
typedef tNodo *tMultiverso;  // Le llamamos tMultiverso según el enunciado (o tgrafo, es válido)


void descubrirMundo(tMultiverso *g, tMundo nuevoMundo){
    tNodo *aux = *g;
    while(aux != NULL){
        if(mundosIguales(aux->info, nuevoMundo) == 1){
            return;
        }
        aux = aux->sig;
    }
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    asignarMundo(&(nuevo->info), nuevoMundo);
    nuevo->portales = NULL;

    nuevo->sig = *g;
    *g = nuevo;
}

void mundosEvacuacion(tMultiverso g, tMundo origen, int maxPeligro, tCola *c) {
    tNodo *aux = g; // 'g' ya es el puntero al primer elemento (paso por valor)

    // 1. Buscamos el mundo de origen desde donde queremos evacuar
    while (aux != NULL && mundosIguales(aux->info, origen) == 0) {
        aux = aux->sig;
    }

    // Si hemos llegado al final y no existe el mundo origen, salimos
    if (aux == NULL) {
        return;
    }

    // 2. Nos metemos en la sub-lista de portales de ese mundo
    ListaAdyacencia portalActual = aux->portales;

    // 3. Recorremos todos los portales disponibles
    while (portalActual != NULL) {
        
        // CONDICIÓN 1: Que no requiera llave (información de la arista)
        if (portalActual->llave == 0) {
            
            // CONDICIÓN 2: Peligro <= maxPeligro (información del vértice destino)
            // Usamos la función del TAD 'obtenerPeligro'
            if (obtenerPeligro(portalActual->destino) <= maxPeligro) {
                
                // Si cumple las dos condiciones, encolamos el mundo destino
                encolar(c, portalActual->destino);
            }
        }
        
        // Avanzamos al siguiente portal de la lista
        portalActual = portalActual->sig;
    }
}

int esPortalBidireccional(tMultiverso g, tMundo origen, tMundo destino) {
    tNodo *aux = g;
    int portalIda = 0;    // Bandera para saber si existe Origen -> Destino
    int portalVuelta = 0; // Bandera para saber si existe Destino -> Origen

    // ==========================================
    // 1. COMPROBAR LA IDA (Origen -> Destino)
    // ==========================================
    while (aux != NULL) {
        if (mundosIguales(aux->info, origen) == 1) {
            
            // Encontramos el origen. Buscamos en sus portales
            ListaAdyacencia actIda = aux->portales;
            while (actIda != NULL) {
                if (mundosIguales(actIda->destino, destino) == 1) {
                    portalIda = 1; // ¡Existe el portal de ida!
                    break;         // Dejamos de buscar en sus portales
                }
                actIda = actIda->sig;
            }
            break; // Dejamos de buscar en los nodos principales
        }
        aux = aux->sig;
    }

    // TRAMPA/OPTIMIZACIÓN: Si ni siquiera hay portal de ida, 
    // no perdemos el tiempo buscando el de vuelta.
    if (portalIda == 0) {
        return 0;
    }

    // ==========================================
    // 2. COMPROBAR LA VUELTA (Destino -> Origen)
    // ==========================================
    aux = g; // ¡MUY IMPORTANTE! Reiniciamos el puntero al principio del multiverso
    
    while (aux != NULL) {
        if (mundosIguales(aux->info, destino) == 1) {
            
            // Encontramos el destino. Buscamos en sus portales
            ListaAdyacencia actVuelta = aux->portales;
            while (actVuelta != NULL) {
                if (mundosIguales(actVuelta->destino, origen) == 1) {
                    portalVuelta = 1; // ¡Existe el portal de vuelta!
                    break;
                }
                actVuelta = actVuelta->sig;
            }
            break;
        }
        aux = aux->sig;
    }

    // ==========================================
    // 3. RESULTADO FINAL
    // ==========================================
    if (portalIda == 1 && portalVuelta == 1) {
        return 1; // Es bidireccional
    } else {
        return 0; // No lo es
    }
}