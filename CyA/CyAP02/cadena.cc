/**  Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Dayán Martínez Arias
 * Correo: alu0101644561@ull.edu.es
 * Fecha: 25/09/24
 * Archivo cadena.cc
 * Contiene la implementación de clase cadena
 * para poder ser realizados los métodos y funcionalidades propuestos en esta práctica.
 * Historial de revisiones
 * 17/09/2024 - Creación (primera versión) del código
 * 18/09/2024 - Creación de métodos y atributos básicos 
 * como la sobrecarga de operadores de insercción y extracción y los constructores
 * 19/09/2024 - Creación de métodos que se piden en la practica como el de invertir cadena
 * 20/09/2024 - Creación de los métodos sufijos y prefijos
 * 21/08/2024 - Aplicación de algunas mejoras, clase terminada.
 */

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
  if (cadena_.length() != other.cadena_.length()) {
    return cadena_.length() < other.cadena_.length();
  }
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
  if(obj.longitud_ == 0) {
    os << "&";
    return os;
  } 
  for (char simbolo : obj.cadena_) {
    os << simbolo;
  }
  return os;
}

bool Cadena::AlfabetoValido(Alfabeto& alfabeto) const {
  for (char simbolo : cadena_) {
    if (!alfabeto.ExisteSimbolo(simbolo)) {
      return false; 
    }
  }
  return true;
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
  Lenguaje aux(alfabeto_);
  std::string prefijo;
  aux.InsertarCadena(Cadena("", alfabeto_));  // Insertar la cadena vacía real
  for (int i = 0; i < cadena_.length(); ++i) {
    prefijo += cadena_[i];  // Construir el prefijo
    aux.InsertarCadena(Cadena(prefijo, alfabeto_));
  }
  return aux;
}

Lenguaje Cadena::Sufijos() {
  Lenguaje aux(alfabeto_);
  aux.InsertarCadena(Cadena("", alfabeto_));  // Insertar la cadena vacía real
  for (int i = 0; i < cadena_.length(); ++i) {
    std::string sufijo = cadena_.substr(i);  // Obtener el sufijo desde la posición i
    aux.InsertarCadena(Cadena(sufijo, alfabeto_));
  }
  return aux;
}


