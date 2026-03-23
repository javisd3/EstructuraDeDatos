// Lee por teclado un polinomio
tPolinomio *leerPolinomio();
// Muestra por pantalla un polinomio
void mostrar(tPolinomio p);
// Devuelve la derivada de un polinomio
void derivada(tPolinomio *pd, tPolinomio p);
// Devuelve el valor de un polinomio aplicado a un valor x
float valor(tPolinomio p, float x);
// Devuelve la suma de dos polinomios
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2);