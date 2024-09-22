#include "tools.h"

bool CheckCorrectParams(const int params, const char opcode) {
  if ((params != kCorrectParams) || (opcode < kLowLim || opcode > kUpLim)) {
    std::cerr << "Número incorrecto de parametros o opcode no valido" << std::endl;
    std::cerr << "Introduzca " << kCorrectParams << " parametros y un opcode del " << kLowLim << " a " << kUpLim << std::endl;
    std::cerr << "Para más información ejecute: p02_strings --help" << std::endl;
    return false;
  } 
  return true;
}

void Uso() {
  std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
  std::cout << "Pruebe ./p02_strings --help para más información." << std::endl;
}

void Ayuda() {
  std::cout << "Cadenas, alfabetos y lenguajes." << std::endl;
  Uso();
  std::cout << "Lista de operaciones: " << std::endl;
  std::cout << "1. Mostrar alfabeto" << std::endl << "2. Mostrar longitud de las cadenas" 
  << std::endl << "3. Mostrar las cadenas invertidas" << std::endl << "4. Mostar los prefijos de las cadenas" 
  << std::endl << "5. Mostrar los sufijos de las cadenas" << std::endl;
}