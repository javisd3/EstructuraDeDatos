void primerCaracterNoEnY(tLista X, tLista Y, tElemento *resultado, int *exito) {
    tNodo *auxX = X;
    *exito = 0; // Inicializamos a 0 (falso). Cambiará a 1 si encontramos el carácter.

    // Recorremos la lista X mientras tenga nodos y no hayamos tenido éxito
    while (auxX != NULL && !(*exito)) {
        
        // Si el carácter actual de X NO pertenece a Y, lo hemos encontrado
        if (!perteneceLista(auxX->info, Y)) {
            *exito = 1; 
            asignarElemento(resultado, auxX->info); // Guardamos el valor para devolverlo
        } else {
            // Si sí pertenece, avanzamos al siguiente nodo de X
            auxX = auxX->sig;
        }
    }
}

void primerCaracterNoEnY(tLista X, tLista ListaY, tElemento *resultado) {
    tNodo *auxX = X;
    int encontrado = 0; // Inicializamos a 0 (falso).

    // Recorremos la lista X mientras tenga nodos y no hayamos tenido éxito
    while (auxX != NULL && !encontrado){
        
        // Si el carácter actual de X NO pertenece a Y, lo hemos encontrado
        if (!perteneceLista(auxX->info, ListaY)) {
            encontrado = 1; // ¡SIN EL INT! Modificamos la variable original
            asignarElemento(resultado, auxX->info); // Guardamos el valor para devolverlo
        } else {
            // Si sí pertenece, avanzamos al siguiente nodo de X
            auxX = auxX->sig;
        }
    }
}

tNodo* primerCaracterNoEnY(tLista X, tLista Y) {
    tNodo *auxX = X;
    int encontrado = 0;

    // Recorremos X mientras haya nodos y no hayamos encontrado nuestro objetivo
    while (auxX != NULL && !encontrado) {
        
        // ¡Ojo a la lógica! Buscamos el que NO está en Y
        if (!perteneceLista(auxX->info, Y)) {
            encontrado = 1; // Lo encontramos, esto romperá el bucle
        } else {
            auxX = auxX->sig; // Si sí está en Y, pasamos al siguiente
        }
    }

    // Si lo encontró, auxX apunta al nodo correcto. 
    // Si terminó la lista sin éxito, auxX será NULL.
    return auxX;
}

