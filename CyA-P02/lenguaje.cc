#include "lenguaje.h"

void Lenguaje::InsertarCadena(const Cadena& cadena_entrada) {
  if (CadenaValida(cadena_entrada)) {
    lenguaje_.insert(cadena_entrada);
  }
}

bool Lenguaje::CadenaValida(const Cadena& cadena_entrada) {
  return cadena_entrada.GetAlfabeto() == GetAlfabeto();
}

Alfabeto Lenguaje::GetAlfabeto() {
  return alfabeto_;
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& obj) {
  os << "{";
  bool first = true;  
  for (const Cadena& simbolo : obj.lenguaje_) { 
    if (!first) {
      os << ", "; 
    }
   os << simbolo;
   first = false;  
  }
  os << "}";
  return os;
}