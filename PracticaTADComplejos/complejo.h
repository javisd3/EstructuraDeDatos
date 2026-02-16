#ifndef COMPLEJO_H
#define COMPLEJO_H

typedef struct {
  float real;
  float imaginario;
} t_complejo;

void CrearComplejo(float r, float i, t_complejo *c);

float parteReal(t_complejo c);
float parteImaginaria(t_complejo c);

float Modulo(t_complejo c);

void Conjugado(t_complejo c, t_complejo *resultado);
void Suma(t_complejo c1, t_complejo c2, t_complejo *resultado);
void Resta(t_complejo c1, t_complejo c2, t_complejo *resultado);
void Multiplicacion(t_complejo c1, t_complejo c2, t_complejo *resultado);
void Division(t_complejo c1, t_complejo c2, t_complejo *resultado);

#endif // COMPLEJO_H