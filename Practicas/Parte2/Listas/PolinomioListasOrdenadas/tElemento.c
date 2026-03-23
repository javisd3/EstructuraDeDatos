// Asigna el valor de un TElemento a otro TElemento
void asignarElemento(tElemento *e1, tElemento e2){

}
// Lee por teclado un TElemento
void leerElemento(tElemento *e){
    scanf("coeficiente:%d, exponente:%d", &e->coeficiente, &e->exponente);
}

// Comprueba si dos TElemento son iguales. Dos términos se consideran
// iguales si tienen el mismo exponente
int igualElemento(tElemento uno, tElemento dos){
    return uno.exponente == dos.exponente;
}

// Comprueba si elem1 es mayor que elem2 (se considera que un termino
//es mayor que otro si el exponente del primero es mayor que el
//exponente del segundo
int mayor(tElemento uno, tElemento dos){
    return uno.exponente > dos.exponente;
}

// Muestra por pantalla un TElemento
void mostrarElemento(tElemento t){
    printf("coeficiente:%d, exponente:%d", t.coeficiente, t.exponente);
}

// Devuelve el exponente de un termino
int getExponente(tElemento e){
    return e.exponente;
}

// Devuelve el coeficiente de un termino
float getCoeficiente(tElemento e){
    return e.coeficiente;
}

// Devuelve la derivada de un termino
void derivada(tElemento *ed, tElemento e){
    
}