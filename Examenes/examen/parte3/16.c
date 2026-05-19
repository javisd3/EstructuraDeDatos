typedef struct {
    char *iban;
    char *titular;
    float saldo;
} tCuenta;

void crearCuenta(tCuenta *destino, char *iban, char *titular, float saldo);
void asignarCuenta(tCuenta *destino, tCuenta origen);
char* obtenerIBAN(tCuenta c);
char* obtenerTitular(tCuenta c);
int iguales(tCuenta c1, tCuenta c2); // Devuelve 1 si son la misma cuenta

typedef struct transferencia {
    tCuenta destino;             
    float cantidad;             
    struct transferencia *sig;  
} tTransferencia;

typedef tTransferencia *tListaTransferencias;


typedef struct nodoCuenta {
    tCuenta info;                           
    tListaTransferencias transferenciasEmitidas; 
    struct nodoCuenta *sig;                 
} tNodoCuenta;

typedef tNodoCuenta *tGrafo;

void registrarCuenta(tGrafo *g, char *iban, char *titular, float saldo) {
    tCuenta nuevaCuenta;
    crearCuenta(&nuevaCuenta, iban, titular, saldo);

    tNodoCuenta *nuevoNodo = (tNodoCuenta*) malloc(sizeof(tNodoCuenta));
    asignarCuenta(nuevoNodo->info, nuevaCuenta);
    nuevoNodo->transferenciasEmitidas = NULL;

    nuevoNodo->sig = *g;
    *g = nuevoNodo;
}

void realizarTransferencia(tGrafo *g, char *ibanOrigen, char *ibanDestino, float cantidad) {
    tNodoCuenta *aux = *g;
    tNodoCuenta *origen = NULL;
    tNodoCuenta *destino = NULL;

    while (aux != NULL && (Origen == NULL || Destino == NULL)){
        if (strcmp(obtenerIBAN(aux), ibanOrigen) == 0){
            origen = aux;
        }
        if (strcmp(obtenerIBAN(aux), ibanDestino) == 0){
            destino = aux;
        }
    aux = aux->sig;
    }

    if (origen == NULL || destino == NULL){
        return;
    } else {
        tTransferencia *nuevaTransferencia = (tTransferencia*) malloc(sizeof(tTransferencia));
        asignarCuenta(nuevaTransferencia->destino, destino->info);
        nuevaTransferencia->cantidad = cantidad;
        nuevaTransferencia->sig = origen->transferenciasEmitidas;
        origen->transferenciasEmitidas = nuevaTransferencia;
    }
}

void imprimirDestinosSospechosos(tGrafo g, char *ibanBuscado) {
    tNodoCuenta *aux = g;

    while (aux != NULL){
        if (strcmp(obtenerIBAN(aux), ibanBuscado) == 0){
            tTransferencia *transfAux = aux->transferenciasEmitidas;

            while (transfAux != NULL){
                printf("%s\n", obtenerIBAN(transfAux->destino);
                transfAux = transfAux->sig;
            }
        return;
        }
    aux = aux->sig;
    }
}

#include <stdio.h>

int contarTransferenciasRecibidas(tGrafo g, tCuenta cuentaBuscada) {
    tNodoCuenta *aux = g; 
    int totalRecibidas = 0;

    // Bucle 1: Recorrer todas las cuentas del grafo
    while (aux != NULL) {
        
        tTransferencia *auxTransf = aux->transferenciasEmitidas;
        // Bucle 2: Recorrer todas las transferencias de la cuenta actual
        while (auxTransf != NULL) {
            
            // Se usa iguales() pasándole los dos datos tipo tCuenta
            if (iguales(auxTransf->destino, cuentaBuscada) == 1) {
                totalRecibidas++;
            }
            auxTransf = auxTransf->sig;
        }
        aux = aux->sig;
    }
    return totalRecibidas;
}

------------------------------------------------------------------------
int TodosSonPares(tArbol a){
    tArbol izq, der;
    tElemento elem;
    int miNumero;
    int loQueYoAporto;

    if (esArbolVacio(a) == 1){
        return 1;
    }

    Raiz(a, &elem);
    miNumero = valor(elem);
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    if ((miNumero % 2) == 0){
        loQueYoAporto = 1;
    }else{
        loQueYoAporto = 0;
    }

    return loQueYoAporto && TodosSonPares(izq) && TodosSonPares(der);
}
------------------------------------------------------------------------
    