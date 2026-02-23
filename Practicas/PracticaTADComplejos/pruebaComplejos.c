#include "complejo.h"

int main() {
  t_complejo z1, z2;
  t_complejo res;

  CrearComplejo(3.0f, 2.0f, &z1);
  CrearComplejo(1.0f, -4.0f, &z2);

  Suma(z1, z2, &res);
  Resta(z1, z2, &res);
  Multiplicacion(z1, z2, &res);
  Division(z1, z2, &res);

  Conjugado(z1, &res);

  Modulo(z1);

  return 0;
}