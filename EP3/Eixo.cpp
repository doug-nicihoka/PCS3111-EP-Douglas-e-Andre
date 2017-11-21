#include "Eixo.h"
#include <stdexcept>

Eixo::Eixo(std::string titulo, double minimo, double maximo, bool orientacaoHorizontal) :
    titulo (titulo), minimo (minimo), maximo (maximo), orientacaoHorizontal (orientacaoHorizontal) {
    if (minimo >= maximo)
        throw new std::runtime_error ("ERRO: Minimo maior ou igual a maximo.");
}

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

bool Eixo::temOrientacaoHorizontal() {
    return orientacaoHorizontal;
}
