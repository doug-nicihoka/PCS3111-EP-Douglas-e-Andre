#include <iostream>
#include "Ponto.h"
using namespace std;

Ponto::Ponto(double x, double y) : x (x), y (y) {}

Ponto::~Ponto() {}

double Ponto::getX() {
    return x;
}

double Ponto::getY() {
    return y;
}

void Ponto::imprimir() {
    cout << "(" << getX() << ", " << getY() << ")" << endl;
}

bool Ponto::eIgual(Ponto* outro) {
    if (getX() >= outro->getX() - 1e-5 && getX() <= outro->getX() + 1e-5)
        if (getY() >= outro->getY() - 1e-5 && getY() <= outro->getY() + 1e-5)
            return true;

    return false;
}
