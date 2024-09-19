#include "alfabeto.h"

/**
 * @brief Construct a new Alfabeto:: Alfabeto object
 * 
 * @param alfabeto 
 */
Alfabeto::Alfabeto(const std::string alfabeto) {
  for(char simbolo : alfabeto) {
    alfabeto_.insert(simbolo);
  }
}

/**
 * @brief 
 * 
 * @param simbolo 
 * @return true 
 * @return false 
 */
bool Alfabeto::ExisteSimbolo(const char simbolo) {
  return (!(alfabeto_.find(simbolo) == alfabeto_.end()));
}

/**
 * @brief 
 * 
 * @param simbolo 
 */
void Alfabeto::InsertarSimbolo(const char simbolo) {
  alfabeto_.insert(simbolo);
}

/**
 * @brief Operador de insercción
 * 
 * @param os 
 * @param obj 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& obj) {
  os << "{";
  bool first = true;  
  for (char simbolo : obj.alfabeto_) { 
    if (!first) {
      os << ", "; 
    }
   os << simbolo;
   first = false;  
  }
  os << "}";
  return os;
}



