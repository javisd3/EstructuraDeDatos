#ifndef PRIORIDAD_H
#define PRIORIDAD_H

// Definimos los colores como números enteros del 1 al 5
typedef enum {
    ROJO = 1,       // Atención inmediata
    NARANJA = 2,    // Prioridad alta
    AMARILLO = 3,   // Prioridad moderada
    VERDE = 4,      // Prioridad baja
    AZUL = 5        // Prioridad muy baja
} tPrioridad;

#endif