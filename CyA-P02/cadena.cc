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

bool Cadena::operator<(const Cadena& other) const {
  return cadena_ < other.cadena_;  
}

bool Cadena::vacia() const {
  return cadena_ == std::string(1, kVacia);
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
  if (!vacia()) {
    return alfabeto_;
  } else {
    Alfabeto();
  }
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

Lenguaje Cadena::Prefijos() {
  Lenguaje aux;
  std::string vacia{"&"};
  for (int i{0}; i <= cadena_.length(); ++i) {
    Cadena cad_aux(vacia, alfabeto_);
    aux.InsertarCadena(cad_aux);
    if(vacia == "&") vacia.clear();
    vacia += cadena_[i];
  }
  return aux;
}

Lenguaje Cadena::Sufijos() {
  Lenguaje aux;
  std::string vacia{"&"};
  aux.InsertarCadena(Cadena(vacia, alfabeto_));  // Insertar cadena vacía primero
  for (int i = 0; i < cadena_.length(); ++i) {
    std::string sufijo = cadena_.substr(i);  // Obtener el sufijo desde la posición i
    aux.InsertarCadena(Cadena(sufijo, alfabeto_));
  }
  return aux;
}

