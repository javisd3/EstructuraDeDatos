void Interseccion(tConjunto c1, tConjunto c2, tConjunto *resultado) {
    resultado->cardinal = 0; // Inicializamos el conjunto resultado como vacío
    
    // Recorremos los elementos del primer conjunto
    for (int i = 0; i < c1.cardinal; i++) {
        // Si el elemento de c1 también pertenece a c2, lo añadimos al resultado
        if (Pertenece(c2, c1.array[i])) {
            resultado->array[resultado->cardinal] = c1.array[i];
            resultado->cardinal++;
        }
    }
}
----------------------------------------------------------------

void Diferencia(tConjunto c1, tConjunto c2, tConjunto *resultado) {
    *resultado = NULL; // Asumimos que CrearConjuntoVacio inicializa a NULL
    
    tNodo* actual = c1;
    
    // Recorremos dinámicamente el conjunto 1
    while (actual != NULL) {
        // Si el elemento de c1 no está en c2, lo ponemos en el resultado
        if (!Pertenece(c2, actual->elem)) {
            Poner(resultado, actual->elem);
        }
        actual = actual->siguiente;
    }
}
----------------------------------------------------------------

// 1. Definición de la estructura para la Bolsa
typedef struct NodoBolsa {
    tElemento elem;
    int multiplicidad; // Nuevo campo para contar repeticiones
    struct NodoBolsa* siguiente;
} tNodoBolsa;

typedef tNodoBolsa* tBolsa;

// 2. Implementación de la función Multiplicidad
int Multiplicidad(tBolsa bolsa, tElemento e) {
    tNodoBolsa* actual = bolsa;
    
    while (actual != NULL) {
        if (actual->elem == e) {
            return actual->multiplicidad; // Elemento encontrado
        }
        actual = actual->siguiente;
    }
    
    return 0; // Si llegamos al final y no se encontró, la multiplicidad es 0
}
----------------------------------------------------------------
int ContarApariciones(tBolsa bolsa, int elementoBuscado) {
    int contador = 0;
    tNodo* actual = bolsa;
    
    // Recorremos toda la lista
    while (actual != NULL) {
        if (actual->elem == elementoBuscado) {
            contador++; // Si coincide, sumamos 1 al contador
        }
        actual = actual->sig;
    }
    return contador;
}