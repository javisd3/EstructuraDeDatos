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

    while(aux != NULL){
        if(iguales(aux->info, m) == 1){
            tlistaAdy *act = aux->afines;
            while(act != NULL){
                if(act->afinidad == 1){
                    tMutante posible = act->vinculo;

                    if(esAmigoReciproco(g,m,posible) == 1{
                    insertar(pListaAfines, posible);
                    }
                } 
            act = act->sig;
            }
            return;
        }
    aux = aux->sig;
    }
}
---------------------------------------------------------------------------------------------