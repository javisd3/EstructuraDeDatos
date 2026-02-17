#include "circuito.h"
#include "complejo.h"
#include <stdio.h>

int main() {
  float v_fuente = 220.0f;
  float frecuencia = 50.0f;
  float R = 5000.0f;
  float L = 0.003f;
  float C = 0.0000012f;

  t_complejo V_total, Z_R, Z_L, Z_C, Z_total, Intensidad;
  t_complejo V_caida_R, V_caida_L, V_caida_C;

  float w = CalcularFrecuenciaAngular(frecuencia);
  printf("--- DATOS DEL CIRCUITO ---\n");
  printf("Frecuencia Angular (w): %.2f rad/s\n", w);

  ImpedanciaResistiva(R, &Z_R);
  ImpedanciaInductiva(L, w, &Z_L);
  ImpedanciaCapacitiva(C, w, &Z_C);

  printf("Impedancia R: %.2f + %.2fi Ohms\n", parteReal(Z_R),
         parteImaginaria(Z_R));
  printf("Impedancia L: %.2f + %.2fi Ohms\n", parteReal(Z_L),
         parteImaginaria(Z_L));
  printf("Impedancia C: %.2f + %.2fi Ohms\n", parteReal(Z_C),
         parteImaginaria(Z_C));

  ImpedanciaTotal(Z_R, Z_L, Z_C, &Z_total);
  printf("Impedancia Total: %.2f + %.2fi Ohms\n", parteReal(Z_total),
         parteImaginaria(Z_total));

  CrearComplejo(v_fuente, 0.0f, &V_total);

  CalcularIntensidad(V_total, Z_total, &Intensidad);
  printf("\n--- RESULTADOS GENERALES ---\n");
  printf("Intensidad del circuito: %.4f + %.4fi Amperios\n",
         parteReal(Intensidad), parteImaginaria(Intensidad));
  printf("Modulo de Intensidad: %.4f A\n", Modulo(Intensidad));

  CalcularCaidaPotencial(Intensidad, Z_R, &V_caida_R);
  CalcularCaidaPotencial(Intensidad, Z_L, &V_caida_L);
  CalcularCaidaPotencial(Intensidad, Z_C, &V_caida_C);

  printf("\n--- CAIDAS DE POTENCIAL (VOLTAJES) ---\n");
  printf("Voltaje en Resistencia (Vr): %.2f + %.2fi V (Mod: %.2f V)\n",
         parteReal(V_caida_R), parteImaginaria(V_caida_R), Modulo(V_caida_R));

  printf("Voltaje en Inductor (Vl):    %.2f + %.2fi V (Mod: %.2f V)\n",
         parteReal(V_caida_L), parteImaginaria(V_caida_L), Modulo(V_caida_L));

  printf("Voltaje en Capacitor (Vc):   %.2f + %.2fi V (Mod: %.2f V)\n",
         parteReal(V_caida_C), parteImaginaria(V_caida_C), Modulo(V_caida_C));

  return 0;
}