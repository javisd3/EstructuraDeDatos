typedef struct NodoAdy{
    tEstudiante Estudiante;
    struct NodoAdy *sig;
}tNodoAdy;

typedef tNodoAdy *Contactos;

typedef struct NodoGrafo{
    tEstudiante info;
    tNodoAdy *contactos;
    struct NodoGrafo *sig;
}tNodoGrafo;

typedef tNodoGrafo *tRedSocial;
----------------------------------------------------------------
void InsertarContacto(TListaContactos *lista, TEstudiante e){
    tNodoAdy *nuevo = (tNodoAdy*) malloc(sizeof(tNodoAdy*));

    Asignar(&(nuevo->Estudiante), e);

    nuevo->sig = *lista;
    *lista = nuevo; 
}
----------------------------------------------------------------
void InsertarContactoEnRed(tRedSocial *g, tEstudiante e){
    tNodoGrafo *aux = *g;
    int MismoGrupo = (Grupo(e) == Grupo(aux->info));
    int EsDelegado = (EsDelegado(e) == EsDelegado(aux->info));


    while (aux != NULL){
        if ((mismoGrupo || ambosDelegados) && !EsIgual(aux->estudiante, e)) {
            InsertarContacto(&(aux->contactos), e);
        }
        aux = aux->sig; 
    }

}
----------------------------------------------------------------
void InsertarNuevoPerfil(tRedSocial *g, tEstudiante e){
    tNodoGrafo *aux = *g;
    while(aux != NULL){
        if (EsIgual(aux->info, e)){
            return;
        }
        aux = aux->sig;
    }
    tNodoGrafo *nuevo = (tNodoGrafo*) malloc (sizeof(tNodoGrafo);
    Asignar(&(nuevo->info), e);
    InsertarContactoEnRed(g,e);
    InsertarAdyacentes(&(nuevo->contactos,  e, g);

    nuevo->sig = *g;
    *g = nuevo;
    }
----------------------------------------------------------------
