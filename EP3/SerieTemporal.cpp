#include "SerieTemporal.h"

SerieTemporal::SerieTemporal(std::string nome, std::string nomeDoCanalY) :
    Serie (nome, "Tempo", nomeDoCanalY) {}

SerieTemporal::~SerieTemporal() {}

void SerieTemporal::adicionar(double valor) {
    pontos->push_back(new Ponto(tempo, valor));
    tempo++;
}
