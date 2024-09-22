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

class Alfabeto {
 public:
  Alfabeto() = default;
  Alfabeto(const std::string alfabeto);
  Alfabeto(const Alfabeto& alfabeto);
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& obj);
  friend std::istream& operator>>(std::istream& is, Alfabeto& obj);
  bool operator==(const Alfabeto& alfabeto) const;
  bool operator!=(const Alfabeto& alfabeto) const;
  bool ExisteSimbolo(const char simbolo);
  void InsertarSimbolo(const char simbolo);
 private:
  std::set<char> alfabeto_;
};

#endif