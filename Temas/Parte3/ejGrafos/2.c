///A
typedef struct NodoAdy{
    tPolitico vecino;
    tFecha fecha;
    struct NodoAdy *sig;
}tNodoAdy;

typedef tNodoAdy *tListas;

typedef struct NodoGrafo{
    tPolitico info;
    tListas vecinos;
    struct NodoGrafo *sig;
}tNodoGrafo;

typedef tNodoGrafo *tGrafo;
----------------------------------------------------------------------------------
///B
void añadirAtaque(Grafo *g, char *polOrigen, char *parOrigen, ind dia, int mes, int año, char *polDestino, char *parDestino){
    tPolitico buscado;
    crearPolitico(&buscado, polOrigen, parOrigen);

    tNodoGrafo *aux = *g;
    while(aux != NULL && !iguales(polOrigen, aux){
        aux = aux->sig;

    }
    if (aux != NULL){
        tNodoAdy conexion = (tNodoAdy*) malloc(sizeof(tNodoAdy*));
        crearPolitico(&(conexion->info), polDestino, parDestino);
        crearFecha(&(Conexion->fecha, dia, mes, año);
        conexion->sig = aux->vecinos;
        aux->vecinos = conexion;
    }
}
----------------------------------------------------------------------------------
///C
void imprimeAtaques(Grafo *g, int dia, int mes, int año){
    tfecha fech;
    crearFecha(&fech, dia, mes, año);

    tNodoGrafo *aux = *g;
    while(aux! = NULL){
        tNodoAdy *Ataque = aux ->vecinos;
        while(Ataque != NULL){
            if (iguales(Ataque->fecha, fech){
                printf("El politico ");
                mostrarPolitico(aux->info);
                printf("ha atacado a ");
                mostrarPolitico (ataque->vecino){
            }
            ataque = ataque->sig;
        }
        aux = aux->sig;
    }
}