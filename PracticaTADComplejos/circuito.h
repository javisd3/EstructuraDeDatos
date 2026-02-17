#ifndef CIRCUITO_H
#define CIRCUITO_H

#include "complejo.h"

#define PI 3.1415926535

float CalcularFrecuenciaAngular(float frecuencia);

/* --- Calculadoras de Impedancias (Z) --- */
/* Rellena un complejo con el valor de la impedancia */
void ImpedanciaResistiva(float R, t_complejo *z);           // Zr = R
void ImpedanciaInductiva(float L, float w, t_complejo *z);  // Zl = j*w*L
void ImpedanciaCapacitiva(float C, float w, t_complejo *z); // Zc = -j / (w*C)

void ImpedanciaTotal(t_complejo zR, t_complejo zL, t_complejo zC,
                     t_complejo *zTotal);

/* (V = I * Z) */
void CalcularIntensidad(t_complejo voltaje, t_complejo impedancia,
                        t_complejo *intensidad);
void CalcularCaidaPotencial(t_complejo intensidad, t_complejo impedancia,
                            t_complejo *voltaje);

#endif