void crearConjunto(tConjunto *c){
    *c=NULL;
}

void poner(tConjunto *c, tElemento elem){
    if(!pertenece(*c, elem)){
        tNodo *aux=(tNodo*)malloc(sizeof(tNodo));
        aisgnarElemento(&aux->info, elem);
        aux->sig=*c;
        *c=aux;   
    }
}

int pertenece(tConjunto c, tElemento elem){
    int encontrado=0; 
    tNodo *aux=c;
    while(aux!=NULL && !pertenece){
        encontrado = igualElemento(aux->info, elem);
        if(!encontrado){
            aux=aux->sig;
        }
    }
    return encontrado;
}

void elegir(tConjunto c, tElemento *elem){
    if(!esConjuntoVacio(c)){
        int card=cardinal(c);
        srand(time(NULL));
        int r = rand()%card;
        tNodo *aux= c;

        int i=0;
        while (i!=r){
            aux=aux->sig;
            i++;
        }
        asignarElemento(elem, aux->info);
    }
}

