#include "circuito.h"
#include <math.h>

float CalcularFrecuenciaAngular(float frecuencia) {
  return 2 * PI * frecuencia;
}

void ImpedanciaResistiva(float R, t_complejo *z) {
  // Usamos tu constructora del módulo complejo
  CrearComplejo(R, 0.0f, z);
}

void ImpedanciaInductiva(float L, float w, t_complejo *z) {
  float parteImaginaria = w * L;
  CrearComplejo(0.0f, parteImaginaria, z);
}

void ImpedanciaCapacitiva(float C, float w, t_complejo *z) {
  // Cuidado: Si C es 0, esto explota. Asumimos C != 0.
  float parteImaginaria = -1.0f / (w * C);
  CrearComplejo(0.0f, parteImaginaria, z);
}

void ImpedanciaTotal(t_complejo zR, t_complejo zL, t_complejo zC,
                     t_complejo *zTotal) {
  t_complejo temp;

  Suma(zR, zL, &temp);

  Suma(temp, zC, zTotal);
}

/* I = V / Z (Ley de Ohm despejada) [cite: 59] */
void CalcularIntensidad(t_complejo voltaje, t_complejo impedancia,
                        t_complejo *intensidad) {
  Division(voltaje, impedancia, intensidad);
}

/* V = I * Z (Ley de Ohm) [cite: 59] */
void CalcularCaidaPotencial(t_complejo intensidad, t_complejo impedancia,
                            t_complejo *voltaje) {
  Multiplicacion(intensidad, impedancia, voltaje);
}