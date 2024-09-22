#include "cadena.h"
#include "lenguaje.h"
#include "tools.h"

void Procesar(std::ifstream& entrada, std::ofstream& salida, const char opcode) {
  std::string linea;
  while (std::getline(entrada, linea)) {
    std::istringstream mi_stream(linea);
    std::string cad;
    Alfabeto alf;
    mi_stream >> cad >> alf;
    Cadena aux(cad, alf);
    if(aux.AlfabetoValido(alf)) {
      switch (opcode) {
        case '1' : 
          salida << aux.GetAlfabeto() << std::endl;
          break;
        case '2' :
          salida << aux.GetLongitud() << std::endl;
          break;
        case '3' :
          salida << aux.Invertir() << std::endl;
          break;
        case '4' :
          salida << aux.Prefijos() << std::endl;
          break;
        case '5' :
          salida << aux.Sufijos() << std::endl;
          break;
      } 
    } else {
      salida << "Cadena no valida" << std::endl;
    }
  }
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