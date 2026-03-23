#ifndef TELEMENTO_H
#define TELEMENTO_H

// Definimos la estructura que representa un único término de un polinomio.
// Por ejemplo, para 3.5x^2, coeficiente = 3.5 y exponente = 2.
typedef struct termino {
    float coeficiente;
    int exponente;
} tElemento;

// Prototipos de las funciones (la "interfaz" de nuestro TAD)
void asignarElemento(tElemento *e1, tElemento e2);
void leerElemento(tElemento *e);
int igualElemento(tElemento uno, tElemento dos);
int mayor(tElemento uno, tElemento dos);
void mostrarElemento(tElemento t);
int getExponente(tElemento e);
float getCoeficiente(tElemento e);
// Usamos un puntero (*ed) para poder modificar el elemento original y devolver el resultado
void derivadaElemento(tElemento *ed, tElemento e);

#endif