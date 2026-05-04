typedef struct NodoLista{
    tSuperHeroe h;
    int escenas;                      ///A
    struct NodoLista *sig;
}tNodoLista;

typedef tNodoLista *tListaAdy;

typedef struct NodoGrafo{
    tSuperHeroe heroe;
    tListaAdy *ady;
    struct NodoGrafo *siguiente;
}tNodoGrafo;

typedef tNodoGrafo *tGrafo;
----------------------------------------------------------------------------------
void insertarSuperheroe(tGrafo *grafo, char *nom, int v, int f){
    tNodoGrafo *aux = (tNodoGrafo*) malloc(sizeof(tNodoGrafo*));
    
    tSuperHeroe nuevo;
    crearSuperHeroe(&nuevo, nom, v, f);
    asignarSuperHeroe(&(aux->h),nuevo);     ///B

    crearVacia(&(aux->ady));

    aux->sig = grafo;
    grafo = aux;
}

void CrearVacia(tLista *l){
    *l = NULL;
}
----------------------------------------------------------------------------------
void crearConexion(tGrafo *grafo, tSuperHeroe super1, tSuperHeroe super2; int escenas){
    char *n1 = obtenerNombre(super1);
    char *n2 = obtenerNombre(super2);
    int numEscenas = numeroSecuencias(*grafo, n1, n2);

    tNodoGrafo *aux = *grafo;
    if (numEscenas == 0){               ///C
        while(!igualSuperHeroe(super1, aux->heroe){
        aux = aux->siguiente;
        }
        Construir(&(aux->ady), super2);

        aux = *grafo;
        while(!igualSuperHeroe(super2, aux->heroe, escenas){
        aux = aux->siguiente;
        }
        Construir(&(aux->ady), super1, escenas);
    }
}

void Construir(tLista l, tSuperHeroe h, int escenas){

}
----------------------------------------------------------------------------------


