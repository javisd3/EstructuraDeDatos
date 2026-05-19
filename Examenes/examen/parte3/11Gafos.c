typedef struct {
    char *id;
    char *region;
    int capacidad;
} tServidor;
void crearServidor(tServidor *destino, char *id, char *region, int capacidad);
void asignarServidor(tServidor *destino, tServidor origen);
char* obtenerID(tServidor s);
char* obtenerRegion(tServidor s);
int iguales(tServidor s1, tServidor s2); // Devuelve 1 si son el mismo, 0 si no


typedef struct conexion {
    tServidor destino;         
    int latencia;              
    struct conexion *sig;     
} tConexion;

typedef tConexion *tListaConexiones; 

typedef struct nodo {
    tServidor info;               
    tListaConexiones aristas;     
    struct nodo *sig;            
} tNodoServidor;

typedef tNodoServidor *tGrafo;

void añadirServidor(tGrafo *g, char *id, char *region, int capacidad){
    tNodoServidor nuevoServer;
    crearServidor(&nuevoServer, id, region, capacidad);

    tNodoServidor *nuevo = (tNodoServidor*) malloc(sizeof(tNodoServidor));
    asignarServidor(&(nuevo->info), nuevoServer);

    nuevo->aristas = NULL;
    nuevo->sig = *g;
    *g = nuevo;
}

void conectarServidores(tGrafo *g, char *id1, char *id2, int latencia){
    tNodoServidor *aux = *g;
    tNodoServidor *origen = NULL;
    tNodoServidor *destino = NULL;

    while (aux != NULL && (origen == NULL || destino == NULL)){
        
        if(strcmp(obtenerID(aux->info),obtenerID(id1)) == 0){
            origen = aux;
        }
        if(strcmp(obtenerID(aux->info),obtenerID(id2)) == 0){
            destino = aux;
        }
        aux = aux->sig;
    }

    if (origen == NULL || destino == NULL){
        return;
    }else{
        tConexion *nuevaConexion1 = (tConexion*) malloc(sizeof(tConexion));
        asignarServidor(&(nuevaConexion1->destino), destino->info);
        nuevaConexion1->latencia = latencia;

        nuevaConexion1->sig = origen->aristas;
        origen->aristas = nuevaConexion1;

        tConexion *nuevaConexion2 = (tConexion*) malloc(sizeof(tConexion));
        asignarServidor(&(nuevaConexion2->destino), origen->info);
        nuevaConexion2->latencia = latencia;

        nuevaConexion2->sig = destino->aristas;
        destino->aristas = nuevaConexion2;
    }
}


void imprimirServidoresPorRegion(tGrafo g, char *regionBuscada) {
    tNodoServidor *aux = g; 
    
    while (aux != NULL){

        if (strcmp(obtenerRegion(aux->info), regionBuscada) == 0){
            printf("%s\n", obtenerID(aux->info));
        }
        aux = aux->sig; 
    }
}
--------------------------------------------------------------------------------
