#ifndef LENGUAJE_H
#define LENGUAJE_H

#include "cadena.h"

class Cadena;

class Lenguaje {
 public:
  Lenguaje() = default;
  void InsertarCadena(const Cadena& cadena_entrada);
  friend std::ostream& operator<<(std::ostream& os, const Lenguaje& obj);
 private:
   std::set<Cadena> lenguaje_;
};

#endif