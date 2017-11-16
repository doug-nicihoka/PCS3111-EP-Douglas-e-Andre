#include "SerieNormal.h"

SerieNormal::SerieNormal(std::string nome, std::string nomeDoCanalX, std::string nomeDoCanalY) :
    Serie (nome, nomeDoCanalX, nomeDoCanalY) {}

SerieNormal::~SerieNormal() {}

void SerieNormal::adicionar(double x, double y) {
    pontos->push_back(new Ponto(x, y));
}
