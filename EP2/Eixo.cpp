#include "Eixo.h"

Eixo::Eixo(std::string titulo, double minimo, double maximo) :
    titulo (titulo), minimo (minimo), maximo (maximo) {}

Eixo::~Eixo() {}

std::string Eixo::getTitulo() {
    return titulo;
}

double Eixo::getMinimo() {
    return minimo;
}

double Eixo::getMaximo() {
    return maximo;
}
