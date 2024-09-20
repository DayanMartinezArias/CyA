#include "lenguaje.h"

void Lenguaje::InsertarCadena(const Cadena& cadena_entrada) {
  lenguaje_.insert(cadena_entrada);
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& obj) {
  os << "{";
  bool first = true;  
  for (Cadena simbolo : obj.lenguaje_) { 
    if (!first) {
      os << ", "; 
    }
   os << simbolo;
   first = false;  
  }
  os << "}";
  return os;
}