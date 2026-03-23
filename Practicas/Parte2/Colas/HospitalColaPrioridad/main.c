#include <stdio.h>
#include <string.h>
#include "hospital.h"

int main() {
    tHospital miHospital;
    tEstudio miEstudio;
    
    inicializarHospital(&miHospital);
    inicializarEstudio(&miEstudio);
    
    // 1. Creamos algunos pacientes de prueba
    tElemento p1 = {"Juan", "Perez", 45, "Dolor pecho", {15, 6, 2023}, ROJO};
    tElemento p2 = {"Ana", "Lopez", 22, "Fractura", {15, 6, 2023}, NARANJA};
    tElemento p3 = {"Luis", "Gomez", 10, "Fiebre", {15, 6, 2023}, AMARILLO};
    
    // Pacientes del 31 de Diciembre
    tElemento p4 = {"Maria", "Sanz", 60, "Ictus", {31, 12, 2023}, ROJO};
    tElemento p5 = {"Carlos", "Ruiz", 28, "Corte", {31, 12, 2023}, NARANJA};

    // 2. Los ingresamos en el hospital
    ingresarPaciente(&miHospital, p1);
    ingresarPaciente(&miHospital, p2);
    ingresarPaciente(&miHospital, p3);
    ingresarPaciente(&miHospital, p4);
    ingresarPaciente(&miHospital, p5);
    
    // 3. Generamos y mostramos el estudio
    generarEstudio(&miHospital, &miEstudio);
    mostrarEstadisticas(miEstudio); // [cite: 2737]
    
    // 4. Borramos el último día del año
    borrarUltimoDia(&miHospital, &miEstudio); // [cite: 2738]
    
    // 5. Mostramos de nuevo para comprobar que se han borrado
    mostrarEstadisticas(miEstudio);
    
    return 0;
}