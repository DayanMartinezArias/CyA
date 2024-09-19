#include "cadena.h"
#include <algorithm>

/**
 * @brief Construct a new Cadena:: Cadena object
 * 
 * @param cadena 
 * @param alfabeto 
 */
Cadena::Cadena(const std::string& cadena, const Alfabeto& alfabeto) 
  : cadena_(cadena), alfabeto_(alfabeto), longitud_(cadena == std::string(1, kVacia) ? 0 : cadena.length()) {
}

/**
 * 
 @brief 
 * 
 * @return int 
 */
int Cadena::GetLongitud() const {
  return longitud_;
}

/**
 * @brief 
 * 
 * @return Alfabeto 
 */
Alfabeto Cadena::GetAlfabeto() const {
  return alfabeto_;
}

/**
 * @brief 
 * 
 * @param os 
 * @param obj 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Cadena& obj) {
  for (char simbolo : obj.cadena_) {
    os << simbolo;
  }
  return os;
}

/**
 * @brief 
 * 
 * @param is 
 * @param obj 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Cadena& obj) {
  std::string nueva_cadena;
  std::string nuevo_alfabeto;
  is >> nueva_cadena >> nuevo_alfabeto;

  obj.cadena_ = nueva_cadena;
  Alfabeto aux;
  for(char simbolo : nuevo_alfabeto) {
    aux.InsertarSimbolo(simbolo);
  }
  obj.alfabeto_ = aux;
  obj.longitud_ = (nueva_cadena == std::string(1, kVacia) ? 0 : nueva_cadena.length());
  return  is;
}

/**
 * @brief 
 * 
 * @return Cadena 
 */
Cadena Cadena::Invertir() {
  std::string inversa{cadena_};
  std::reverse(inversa.begin(), inversa.end());
  return Cadena(inversa, alfabeto_);
} 

