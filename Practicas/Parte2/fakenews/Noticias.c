#include "Noticias.h"


int contarVisitas(tLista lista){
    tNodo *aux=lista;
    while(aux!=NULL){
        suma+=getVisitas(aux->info);
    }
    return suma;
}
