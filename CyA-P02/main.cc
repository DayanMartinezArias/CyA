#include "cadena.h"
#include "salida-entrada.h"
#include <fstream>
#include <sstream>

void Procesar(std::ifstream& entrada, std::ofstream& salida, const char opcode) {
  std::string linea, linea_alfabeto;
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
    } 
  }
}


int main (int argc, char* argv[]) {
  std::ifstream entrada(argv[1]);
  std::ofstream salida(argv[2]);
  std::string linea3{argv[3]};
  char opcode{linea3[0]};
  if (entrada.is_open() && salida.is_open()) {
    Procesar(entrada, salida, opcode);
  } else {
    std::cerr << "Error al abrir los archivos" << std::endl;
  }
  return 0;
}