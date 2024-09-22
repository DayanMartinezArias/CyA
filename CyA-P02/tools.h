#include <fstream>
#include <sstream>
#include <iostream>

constexpr int kCorrectParams{4};
constexpr char kLowLim{'1'}, kUpLim{'5'};

bool CheckCorrectParams(const int params, const char opcode);
void Uso();
void Ayuda();