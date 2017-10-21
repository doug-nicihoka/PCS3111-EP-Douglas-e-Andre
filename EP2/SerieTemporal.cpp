#include "SerieTemporal.h"
#include <cmath>

SerieTemporal::SerieTemporal(string nome, string nomeDoCanalY) : Serie (nome, "Tempo", nomeDoCanalY) {}

SerieTemporal::~SerieTemporal() {}

void SerieTemporal::adicionar(double valor) {
    for (int i = 0; i < quantidade; i++)
        if (abs((getPosicao(i)->getX()) - tempo) <= 1e-5) {
            eixoY[i] = valor;
            tempo += 1;
            return;
        }

    Serie::adicionar(tempo, valor);
    tempo += 1;
}

void SerieTemporal::adicionar(double x, double y) {
    for (int i = 0; i < quantidade; i++)
        if (abs(getPosicao(i)->getX() - x) <= 1e-5) {
            eixoY[i] = y;
            return;
        }

    Serie::adicionar(x, y);
}
