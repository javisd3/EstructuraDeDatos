#include <stdio.h>
#include "dioses.h"

int main() {
    tArbol arbolMitologico;
    
    // 1. Crear el árbol
    printf("Construyendo el Arbol Genealogico...\n\n");
    crearArbolDioses(&arbolMitologico);
    
    // 2. Imprimir preorden
    // La salida esperada según el PDF es: Cronos, Zeus, Atenea, Dédalo, Apolo, Orfeo, Aristeo, Hera, Hefeso, Ares.
    printf("--- RECORRIDO PREORDEN (Raiz, Izquierdo, Derecho) ---\n");
    imprimirPreorden(arbolMitologico);
    printf("\n\n");
    
    // 3. Comprobar si existe un dios
    printf("--- COMPROBAR EXISTENCIA ---\n");
    char dios1[] = "Apolo";
    char dios2[] = "Poseidon";
    printf("¿Existe %s? %s\n", dios1, existeDios(arbolMitologico, dios1) ? "SI" : "NO");
    printf("¿Existe %s? %s\n\n", dios2, existeDios(arbolMitologico, dios2) ? "SI" : "NO");
    
    // 4. Comprobar parentesco
    printf("--- COMPROBAR PARENTESCO ---\n");
    printf("¿Es Zeus padre de Atenea? %s\n", esPadre(arbolMitologico, "Zeus", "Atenea") ? "SI" : "NO");
    printf("¿Es Zeus padre de Orfeo? %s\n", esPadre(arbolMitologico, "Zeus", "Orfeo") ? "SI" : "NO");
    printf("¿Es Cronos padre de Hera? %s\n", esPadre(arbolMitologico, "Cronos", "Hera") ? "SI" : "NO");

    return 0;
}