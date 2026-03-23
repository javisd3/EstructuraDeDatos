#include <stdio.h>
#include "elemento.h"

void mostrarElemento(tElemento e) {
    printf("Paciente: %s %s | Edad: %d | Fecha: %02d/%02d/%d | Prioridad: %d\n", 
           e.nombre, e.apellidos, e.edad, e.fecha.dia, e.fecha.mes, e.fecha.anio, e.prioridad);
}