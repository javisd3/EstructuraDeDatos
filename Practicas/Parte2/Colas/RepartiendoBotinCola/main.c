#include <stdio.h>
#include "coladinamica.h"
#include "colaenteros.h"

int main() {
    tColaBandidos colaSecuaces;
    tColaDinero fajoBilletes;
    int numSecuaces, numBilletes;
    char nombreTemp[50];
    tElemento billeteActual;
    tBandido secuazActual;

    // 1. Inicializamos las colas
    crearColaBandidos(&colaSecuaces);
    crearColaDinero(&fajoBilletes);

    // 2. Leemos los secuaces y los metemos a la cola
    printf("Dime el numero de secuaces de la banda\n");
    scanf("%d", &numSecuaces);

    for (int i = 0; i < numSecuaces; i++) {
        printf("Nombre\n");
        scanf("%s", nombreTemp);
        
        inicializarBandido(&secuazActual, nombreTemp);
        encolarBandido(&colaSecuaces, secuazActual);
    }

    // 3. Leemos los billetes y montamos el fajo
    printf("Vamos a ver el botin\n");
    printf("Numero de billetes\n");
    scanf("%d", &numBilletes);

    for (int i = 0; i < numBilletes; i++) {
        printf("Billete %d\n", i + 1);
        scanf("%d", &billeteActual);
        encolarDinero(&fajoBilletes, billeteActual);
    }

    // 4. EL REPARTO (La magia de tu idea)
    // Mientras haya billetes en el fajo, seguimos repartiendo
    while (!colaDineroVacia(fajoBilletes)) {
        // Sacamos el billete de arriba
        desencolarDinero(&fajoBilletes, &billeteActual);
        
        // Sacamos al primero de la fila
        desencolarBandido(&colaSecuaces, &secuazActual);
        
        // Le damos el billete
        sumarDinero(&secuazActual, billeteActual);
        
        // ¡Al final de la cola otra vez!
        encolarBandido(&colaSecuaces, secuazActual);
    }

    // 5. Imprimir los resultados
    // Como los fuimos rotando, siguen en el orden correcto en la cola. 
    // Solo tenemos que ir sacándolos hasta que la cola quede vacía.
    printf("\n");
    while (!colaBandidosVacia(colaSecuaces)) {
        desencolarBandido(&colaSecuaces, &secuazActual);
        mostrarBandido(secuazActual);
    }

    return 0;
}