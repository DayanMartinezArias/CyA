#ifndef LENGUAJE_H
#define LENGUAJE_H

#include "cadena.h"

class Cadena;

class Lenguaje {
 public:
  Lenguaje() = default;
  Lenguaje(const Alfabeto& alfabeto) : alfabeto_(alfabeto) {};
  void InsertarCadena(const Cadena& cadena_entrada);
  Alfabeto GetAlfabeto();
  friend std::ostream& operator<<(std::ostream& os, const Lenguaje& obj);
 private:
   bool CadenaValida(const Cadena& cadena_entrada);

   std::set<Cadena> lenguaje_;
   Alfabeto alfabeto_;
};

#endif