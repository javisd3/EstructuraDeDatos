ESPECIFICACION
  ...
OPERACIONES
  NumeroHijosUnicos : TipoArbolBin -> TipoEntero

ECUACIONES
  // Caso 1: El árbol está vacío.
  NumeroHijosUnicos(CrearArbolVacio) = 0
  
  // Caso 2: Tiene hijo izquierdo, pero el derecho está vacío. Sumamos 1 y miramos la rama izquierda.
  NumeroHijosUnicos(Construir(izq, raiz, der)) = 
      SI NO EsArbolVacio(izq) Y EsArbolVacio(der) ->
          1 + NumeroHijosUnicos(izq)
          
  // Caso 3: Tiene hijo derecho, pero el izquierdo está vacío. Sumamos 1 y miramos la rama derecha.
      | SI EsArbolVacio(izq) Y NO EsArbolVacio(der) ->
          1 + NumeroHijosUnicos(der)
          
  // Caso 4: Tiene ambos hijos (ninguno es único), o es una hoja (no tiene hijos). Miramos ambas ramas.
      |
          NumeroHijosUnicos(izq) + NumeroHijosUnicos(der)
------------------------------------------------------
tNodoLista* buscarCardenal(tGrafo g, tElemento buscado) {
    tNodoLista *act = g; 
    
    while (act != NULL) {
        if (iguales(act->info, buscado)) {
            return act; 
        }
        act = act->sig; 
    }
    return NULL; 
}

int haVotado(tGrafo g, tElemento uno, tElemento dos) {
    tNodoLista *nodoUno = buscarCardenal(g, uno);
    
    if (nodoUno == NULL) {
        return 0; 
    }
    
    tNodoAdy *actAdy = nodoUno->ady;
    
    while (actAdy != NULL) {
        if (iguales(actAdy->info, dos)) { 
            return 1;
        }
        actAdy = actAdy->sig;
    }
    
    return 0;
}

int existePacto(tGrafo g, tElemento uno, tElemento dos) {
    if (haVotado(g, uno, dos) == 1 && haVotado(g, dos, uno) == 1) {
        return 1;
    }
    return 0;
}
------------------
tNodoLista* buscarEstacion(tGrafo g, tElemento buscada) {* buscarEstacion(tGrafo g, tElemento buscada) {
    tNodoLista *aux = g;

    while (aux != NULL){
        if (iguales(aux->info, buscada){
        return aux;
        }
    aux = aux->sig;
    }
    return NULL;
}

int hayRutaDirecta(tGrafo g, tElemento origen, tElemento destino) {
    tNodoLista *aux = buscarEstacion(g, origen);

    if (origen == NULL){
        return 0;
    }
----------------------------------------------------------------------------

int ExisteNegativo(tArbol a){
    tArbol izq,der;
    tElemento elem;
    float miNumero;
    float loqueyoAporto;

    if (esArbolVacio(a) == 0){
        return 0;
    }

    Raiz(a, &elem);
    HijoIzq(a, &izq);
    HijoDer(a, &der);
    miNumero = valor(elem);

    if (miNumero < 0){
        loqueyoAporto = 1;
    }else {
        loqueyoAporto = 0;
    }

    return loqueyoAporto || ExisteNegativo(izq) || ExisteNegativo(der);
}
----------------------------------------------------------------------------
Especificación
Obs no selectora
Operaciones
NodosConUnHijo: TipoArbol -> TipoEntero

Ecuaciones

NodosConUnHijo(CrearArbolVacio) = 0;

NodosConUnHijo(Construir(izq, raiz, der)) =
    SI esArbolVacio(izq) Y NO esArbolVacio(der) = 1 + NodosConUnHijo(der) |
        SI esArbolVacio(der) Y NO esArbolVacio(izq) = 1 + NodosConUnHijo(izq) |
            NodosConUnHijo(der) + NodosConUnHijo(izq) 
----------------------------------------------------------------------------
typedef struct {
    char *nombre;
    int creditos;
    int curso;
} tAsignatura;
void crearAsignatura(tAsignatura *destino, char *nombre, int creditos, int curso);
void asignarAsignatura(tAsignatura *destino, tAsignatura origen);
char* obtenerNombre(tAsignatura a);
int iguales(tAsignatura a1, tAsignatura a2); // Devuelve 1 si son la misma asignatura

typedef struct nodoPrerrequisito {
    tAsignatura destino;            
    int notaMinima;                 
    struct nodoPrerrequisito *sig;   
} tNodoPrerrequisito;
typedef tNodoPrerrequisito *tListaPrerrequisitos;

typedef struct nodoAsignatura {
    tAsignatura info;                       
    tListaPrerrequisitos desbloqueadas;   
    struct nodoAsignatura *sig;            
} tNodoAsignatura;
typedef tNodoAsignatura *tGrafo;

void añadirAsignatura(tGrafo *g, char *nombre, int creditos, int curso) {
    tAsignatura nuevaAsig;
    crearAsignatura(&nuevaAsig, nombre, creditos, curso);
    tNodoAsignatura *nuevoNodo = (tNodoAsignatura*) malloc(sizaof(tNodoAsignatura));

    asignarAsignatura(&(nuevoNodo->info), nuevaAsig);
    nuevoNodo->desbloqueadas = NULL;

    nuevoNodo->sig = *g;
    *g = nuevoNodo;
}
void establecerPrerrequisito(tGrafo *g, char *asignaturaPrevia, char *asignaturaSiguiente, int notaMinima) {
    tNodoAsignatura *aux = *g;
    tNodoAsignatura *previa = NULL;
    tNodoAsignatura *siguiente = NULL;

    // 1. Buscamos ambas asignaturas en la base de datos
    while (aux != NULL && (previa == NULL || siguiente == NULL)) {
        if (strcmp(obtenerNombre(aux->info), asignaturaPrevia) == 0) {
            previa = aux;
        }
        if (strcmp(obtenerNombre(aux->info), asignaturaSiguiente) == 0) {
            siguiente = aux;
        }
        aux = aux->sig;
    }

    // 2. Si alguna de las dos no existe, salimos
    if (previa == NULL || siguiente == NULL) {
        return; 
    } else {
        tNodoPrerrequisito *nuevoPre = (tNodoPrerrequisito*) malloc(sizeof(tNodoPrerrequisito));
        asignarAsignatura(&(nuevoPre->destino), siguiente->info);
        nuevoPre->notaMinima = notaMinima;

        nuevoPre->sig = previa->desbloqueadas;
        previa->desbloqueadas = nuevoPre;
    }
}
void imprimirAsignaturasDesbloqueadas(tGrafo g, char *asignaturaAprobada) {
    tNodoAsignatura * aux = g;
    while(aux!= NULL){
        if(strcmp(aux->info, asignaturaAprobada) == 0){
            tNodoPrerrequisito *act = aux;
            while(act != NULL){
                printf("%s\n", obtenerNombre(act->info);
                act = act->sig;
            }
            return;
        }
        aux = aux->sig;
    }
}
