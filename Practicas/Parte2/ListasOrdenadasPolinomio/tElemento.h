typedef struct termino{
    float coeficiente;
    int exponente;
}tElemento;

// Asigna el valor de un TElemento a otro TElemento
void asignarElemento(tElemento *e1, tElemento e2);
// Lee por teclado un TElemento
void leerElemento(tElemento *e);
// Comprueba si dos TElemento son iguales. Dos términos se consideran
// iguales si tienen el mismo exponente
int igualElemento(tElemento uno, tElemento dos);
// Comprueba si elem1 es mayor que elem2 (se considera que un termino
//es mayor que otro si el exponente del primero es mayor que el
//exponente del segundo
int mayor(tElemento uno, tElemento dos);
// Muestra por pantalla un TElemento
void mostrarElemento(tElemento t);
// Devuelve el exponente de un termino
int getExponente(tElemento e);
// Devuelve el coeficiente de un termino
float getCoeficiente(tElemento e);
// Devuelve la derivada de un termino
void derivada(tElemento *ed, tElemento e);