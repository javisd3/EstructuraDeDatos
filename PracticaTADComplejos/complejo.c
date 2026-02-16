#include "complejo.h"
#include <math.h>

void CrearComplejo(float r, float i, t_complejo *c) {
  c->real = r;
  c->imaginario = i;
}

float parteReal(t_complejo c) { return c.real; }

float parteImaginaria(t_complejo c) { return c.imaginario; }

float Modulo(t_complejo c) {
  return sqrt(pow(c.real, 2) + pow(c.imaginario, 2));
}

void Conjugado(t_complejo c, t_complejo *resultado) {
  resultado->real = c.real;
  resultado->imaginario = -c.imaginario;
}

void Suma(t_complejo c1, t_complejo c2, t_complejo *resultado) {
  resultado->real = c1.real + c2.real;
  resultado->imaginario = c1.imaginario + c2.imaginario;
}

void Resta(t_complejo c1, t_complejo c2, t_complejo *resultado) {
  resultado->real = c1.real - c2.real;
  resultado->imaginario = c1.imaginario - c2.imaginario;
}

void Multiplicacion(t_complejo c1, t_complejo c2, t_complejo *resultado) {
  float r = (c1.real * c2.real) - (c1.imaginario * c2.imaginario);
  float i = (c1.imaginario * c2.real) + (c1.real * c2.imaginario);

  resultado->real = r;
  resultado->imaginario = i;
}

void Division(t_complejo c1, t_complejo c2, t_complejo *resultado) {
  float den = pow(c2.real, 2) + pow(c2.imaginario, 2);
  float r = ((c1.real * c2.real) + (c1.imaginario * c2.imaginario)) / den;
  float i = ((c1.imaginario * c2.real) - (c1.real * c2.imaginario)) / den;

  resultado->real = r;
  resultado->imaginario = i;
}
