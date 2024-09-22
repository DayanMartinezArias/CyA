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
 * para poder ser realizados los métodos y funcionalidades propuestos en esta práctica.
 * Historial de revisiones
 * 17/09/2024 - Creación (primera versión) del código
 * 18/09/2024 - Creación de métodos y atributos básicos 
 * como la sobrecarga de operadores de insercción y extracción y los constructores
 * 19/09/2024 - Creación de métodos que se piden en la practica como el de invertir cadena
 * 20/09/2024 - Creación de los métodos sufijos y prefijos
 * 21/08/2024 - Aplicación de algunas mejoras, clase terminada.
 */

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