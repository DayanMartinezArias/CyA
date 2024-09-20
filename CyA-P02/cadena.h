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

#ifndef CADENA_H
#define CADENA_H

#include <set>
#include "alfabeto.h"
#include "lenguaje.h"

class Lenguaje;
constexpr char kVacia{'&'};

class Cadena {
 public:
  Cadena() = default;
  Cadena(const std::string& cadena, const Alfabeto& alfabeto);
  int GetLongitud() const;
  Alfabeto GetAlfabeto() const;
  Cadena Invertir();
  bool operator<(const Cadena& other) const;
  bool vacia() const;
  Lenguaje Prefijos();
  Lenguaje Sufijos();
  friend std::ostream& operator<<(std::ostream& os, const Cadena& obj);
  friend std::istream& operator>>(std::istream& is, Cadena& obj);
 private:
  std::string cadena_;
  Alfabeto alfabeto_;
  int longitud_;
};

#endif