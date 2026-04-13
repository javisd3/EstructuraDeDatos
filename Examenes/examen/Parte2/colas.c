Longitud: TipoCola -> Natural

Longitud(CrearColaVacia) = 0

Longitud(Insertar(e, cola)) = 1 + Longitud(cola)
---------------------------------------------------------------------------------------------------------
void concatenarColas(tCola *c1, tCola *c2) {
    // Si la segunda cola está vacía, no hay nada que hacer
    if (c2->cabecera == NULL) return;
    
    // Si la primera cola está vacía, c1 se convierte en c2
    if (c1->cabecera == NULL) {
        c1->cabecera = c2->cabecera;
        c1->final = c2->final;
    } else {
        // Enganchamos el último nodo de c1 al primer nodo de c2
        c1->final->sig = c2->cabecera;
        // Actualizamos el puntero final de c1 para que apunte al final de c2
        c1->final = c2->final;
    }
    
    // Vaciamos c2 (dejamos sus punteros a NULL)
    c2->cabecera = NULL;
    c2->final = NULL;
}
---------------------------------------------------------------------------------------------------------
void rotarCola(tColaCircular *c) {
    // Si la cola no está vacía ni tiene un solo elemento
    if (*c != NULL) {
        // Avanzamos el puntero Final al siguiente nodo.
        // Al hacer esto, el antiguo "Primero" pasa a ser el nuevo "Final".
        // ¡Y el anillo físico no se rompe en ningún momento!
        *c = (*c)->sig; 
    }
}