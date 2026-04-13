Reemplazar: TipoLista x TipoElemento x TipoElemento -> TipoLista

Reemplazar(CrearVacia, viejo, nuevo) = CrearVacia

Reemplazar(Construir(e, lista), viejo, nuevo) = Si Igual(e, viejo) -> 
    Construir(nuevo, Reemplazar(lista, viejo, nuevo)) | Construir(e, Reemplazar(lista, viejo, nuevo))

---------------------------------------------------------------------------------------------------------
void duplicarNodos(tLista *l) {
    tNodo *aux = *l;
    
    // Mientras haya nodos que duplicar
    while (aux != NULL) {
        // 1. Creamos el nuevo nodo
        tNodo *nuevo = (tNodo*)malloc(sizeof(tNodo));
        nuevo->info = aux->info; // Copiamos el valor
        
        // 2. Enlazamos el nuevo nodo justo después del actual
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
        
        // 3. Avanzamos el puntero a la siguiente pareja original
        // (Saltamos el nodo actual y el que acabamos de crear)
        aux = nuevo->sig; 
    }
}
---------------------------------------------------------------------------------------------------------
int estaOrdenada(tLista l) {
    // Caso base 1: Lista vacía o hemos llegado al final.
    if (l == NULL) return 1;
    
    // Caso base 2: Es el último elemento, no hay nadie con quien comparar.
    if (l->sig == NULL) return 1;
    
    // Si el elemento actual es MAYOR que el siguiente, rompe el orden
    if (l->info > l->sig->info) {
        return 0; // Falso
    }
    
    // Caso recursivo: Si este par está bien, comprobamos el resto
    return estaOrdenada(l->sig);
}
---------------------------------------------------------------------------------------------------------
Contar: TipoLista x TipoElemento -> Natural

Contar(CrearVacia, elem) = 0

Contar(Construir(e, lista), elem) = SI Igual(e, elem) 
    ENTONCES 1 + Contar(lista, elem) SINO Contar(lista, elem)
---------------------------------------------------------------------------------------------------------
void eliminarMayoresQue(tLista *l, int limite) {
    tNodo *act = *l;
    tNodo *ant = NULL;
    
    while (act != NULL) {
        if (act->info > limite) {
            tNodo *aux = act; // Guardamos el nodo a borrar
            
            if (ant == NULL) {
                // Caso A: El nodo a borrar es el primero de la lista
                *l = act->sig;
                act = *l; // Actualizamos 'act' al nuevo primero
            } else {
                // Caso B: El nodo a borrar está en medio o al final
                ant->sig = act->sig;
                act = ant->sig; // Actualizamos 'act' al siguiente válido
            }
            free(aux); // ¡Liberamos la memoria!
            
        } else {
            // Si no hay que borrarlo, simplemente avanzamos los dos punteros
            ant = act;
            act = act->sig;
        }
    }
}
---------------------------------------------------------------------------------------------------------
BorrarTodos(CrearVacia, elem) = CrearVacia

BorrarTodos(Construir(e, lista), elem) = Si Igual(e, elem) -> 
        BorrarTodos(lista, elem) | Construir(e, BorrarTodos(lista, elem))
---------------------------------------------------------------------------------------------------------
void dividirLista(tLista *L, tLista *L_Pares, tLista *L_Impares) {
    // 1. Inicializamos las listas de destino a vacío
    *L_Pares = NULL;
    *L_Impares = NULL;
    
    tNodo *act = *L;
    tNodo *sigAux = NULL;
    
    // 2. Recorremos la lista original
    while (act != NULL) {
        // ¡CUIDADO! Guardamos el enlace al siguiente antes de romper la cuerda
        sigAux = act->sig;
        
        // 3. Evaluamos y re-enganchamos el nodo actual (insertando por cabecera)
        if (act->info % 2 == 0) { // Es par
            act->sig = *L_Pares;  // El nodo apunta a la antigua cabecera de pares
            *L_Pares = act;       // El nodo se convierte en la nueva cabecera
        } else {                  // Es impar
            act->sig = *L_Impares;
            *L_Impares = act;
        }
        
        // 4. Avanzamos en la lista original usando el enlace que guardamos
        act = sigAux;
    }
    
    // 5. La lista original se queda vacía
    *L = NULL;
}
---------------------------------------------------------------------------------------------------------
int sonIguales(tLista L1, tLista L2) {
    // Caso base 1: Ambas han llegado al final a la vez. ¡Son iguales!
    if (L1 == NULL && L2 == NULL) {
        return 1;
    }
    
    // Caso base 2: Una ha llegado al final pero la otra no (distinta longitud).
    if (L1 == NULL || L2 == NULL) {
        return 0;
    }
    
    // Caso base 3: Los elementos en la posición actual son distintos.
    if (L1->info != L2->info) {
        return 0;
    }
    
    // Caso recursivo: Si los actuales son iguales, seguimos comparando el resto.
    return sonIguales(L1->sig, L2->sig);
}
---------------------------------------------------------------------------------------------------------
