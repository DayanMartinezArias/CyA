/**  Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Dayán Martínez Arias
 * Correo: alu0101644561@ull.edu.es
 * Fecha: 25/09/24
 * Archivo cadena.h
 * Contiene la clase cadena
 * para ... (indicar brevemente el objetivo)
 * Referencias:
 * Enlaces de interés
 * Historial de revisiones
 * 17/09/2024 - Creación (primera versión) del código
 */

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <iostream>

typedef char simbolo;

class Alfabeto {
 public:
  Alfabeto(const std::string alfabeto);
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& obj);
 private:
  std::set<simbolo> alfabeto_;
};

#endif