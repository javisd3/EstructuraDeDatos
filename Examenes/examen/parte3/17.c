typedef struct listaAdy{
    tMutante vinculo;
    int afinidad;
    struct listaAdy *sig;
}tlistaAdy;

typedef tlistaAdy *ListaAfinidad:

typedef struct nodo{
    tMutante info;
    ListaAfinidad afines;
    struct nodo *sig;
}tNodo;

typedef tNodo *tRedMutantes;

void insertarMutante(tRedMutantes *g, int id, char *nom, int poder, char *type) {
    tMutante nuevoMutante;
    crearMutante(&nuevo, id, nom, poder, type);

    tNodo *aux = *g;
    while(aux != NULL){
        if(iguales(aux->info, nuevoMutante) == 1){
            return;
        }
        aux = aux->sig;
    }

    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));

    asignarMutante(&(nuevoNodo), nuevoMutante);
    nuevoNodo->afines = NULL;

    nuevoNodo->sig = *g;
    *g = nuevoNodo;
}

void mutantesAfines(tRedMutantes *g, tMutante m, tLista *pListaAfines) {
    tNodo *aux = *g;

    while(aux!=NULL){
        if(iguales(aux->info,m) == 1){
            tlistaAdy *act = aux->afines;
            while(act != NULL){
                if(act->afinidad == 1){
                    tMutante posible =act->vinculo;
                    int esreciproco = 0;

                    tNodo *aux2 = *g;
                    while(aux2 != NULL){
                        if(iguales(aux->info, m) == 1){
                            tlistaAdy *act2 = aux2 ->afines;
                            if(act2->afinidad == 1){
                                int esreciproco = 1;
                            }
                            break;
                        }
                        act2=act2->sig;
                    }
                    break;
                }
                aux2=aux2->sig;
            }

            if(esreciproco == 1){
                insertar(pListaAfines, posible);
            }
        }
        act = act->sig;
    }
    return;
aux=aux->sig;
}
-----------------------------------------------------------------------------------------------------
void mutantesAfines(tRedMutantes *g, tMutante m, tLista *pListaAfines) {
    tNodo *aux = *g;

    while(aux != NULL) {
        // Encontramos a nuestro mutante 'm'
        if(iguales(aux->info, m) == 1) {
            
            tlistaAdy *act = aux->afines;
            
            // Recorremos sus conexiones
            while(act != NULL) {
                // Si le cae bien alguien...
                if(act->afinidad == 1) {
                    tMutante posible = act->vinculo;
                    
                    // ¡MAGIA! Llamamos a la función auxiliar para no anidar código
                    if(esAmigoReciproco(g, m, posible) == 1) {
                        insertar(pListaAfines, posible);
                    }
                }
                act = act->sig; // Avanzamos al siguiente amigo
            }
            
            return; // Ya hemos procesado a 'm', salimos de la función principal
        }
        
        aux = aux->sig; // Avanzamos al siguiente mutante de la red
    }
}


int esAmigoReciproco(tRedMutantes *g, tMutante origen, tMutante destino) {
    tNodo *aux = *g;
    
    // 1. Buscamos al posible amigo en la red
    while(aux != NULL) {
        if(iguales(aux->info, destino) == 1) {
            
            // 2. Entramos en su lista de amigos
            tlistaAdy *act = aux->afines;
            while(act != NULL) {
                // Si en su lista está nuestro mutante original con afinidad 1, ¡es recíproco!
                if(iguales(act->vinculo, origen) == 1 && act->afinidad == 1) {
                    return 1; 
                }
                act = act->sig;
            }
            return 0; // Si miramos su lista y no estábamos, no es recíproco
        }
        aux = aux->sig;
    }
    return 0; // Si ni siquiera encontramos al mutante
}
---------------------------------------------------------------------------------------------