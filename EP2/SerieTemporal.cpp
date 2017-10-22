#include "SerieTemporal.h"
#include <cmath>

SerieTemporal::SerieTemporal(std::string nome, std::string nomeDoCanalY) : Serie (nome, "Tempo", nomeDoCanalY) {}

SerieTemporal::~SerieTemporal() {}

void SerieTemporal::adicionar(double valor) {
    for (int i = 0; i < quantidade; i++)
        if (std::abs((getPosicao(i)->getX()) - tempo) <= 1e-5) {
            eixoY[i] = valor;
            tempo += 1;
            return;
        }

    Serie::adicionar(tempo, valor);
    tempo += 1;
}

void SerieTemporal::adicionar(double x, double y) {
    if (x < 1)
        return;
    for (int i = 0; i < quantidade; i++)
        if (std::abs(getPosicao(i)->getX() - x) <= 1e-5) {
            eixoY[i] = y;
            return;
        }

    Serie::adicionar(x, y);
}
