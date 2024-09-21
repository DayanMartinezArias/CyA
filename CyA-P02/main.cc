#include "cadena.h"
#include "lenguaje.h"
#include <fstream>
#include <sstream>

constexpr int kCorrectParams{4};
constexpr char kLowLim{'1'}, kUpLim{'5'};

void Procesar(std::ifstream& entrada, std::ofstream& salida, const char opcode) {
  std::string linea;
  while (std::getline(entrada, linea)) {
    std::istringstream mi_stream(linea);
    Cadena cad;
    mi_stream >> cad;
    switch (opcode) {
      case '1' : 
        salida << cad.GetAlfabeto() << std::endl;
        break;
      case '2' :
        salida << cad.GetLongitud() << std::endl;
        break;
      case '3' :
        salida << cad.Invertir() << std::endl;
        break;
      case '4' :
        salida << cad.Prefijos() << std::endl;
        break;
      case '5' :
        salida << cad.Sufijos() << std::endl;
        break;
    } 
  }
}

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

int main (int argc, char* argv[]) {
  if(argc == 1) {
    Uso();
    return 0;
  }
  std::string arg1{argv[1]};
  if (arg1 == "--help") {
    Ayuda();
    return 0;
  }
  std::string arg2{argv[2]};
  std::ifstream entrada(arg1);
  std::ofstream salida(arg2);
  std::string arg3{argv[3]};
  char opcode{arg3[0]};
  if (!CheckCorrectParams(argc, opcode)) {
    entrada.close();
    salida.close();
    return 1;
  }
  if (entrada.is_open() && salida.is_open()) {
    Procesar(entrada, salida, opcode);
  } else {
    std::cerr << "Error al abrir los archivos" << std::endl;
    entrada.close();
    salida.close();
    return 1;
  }
  entrada.close();
  salida.close();
  return 0;
}