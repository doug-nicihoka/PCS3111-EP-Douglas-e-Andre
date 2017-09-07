#include <iostream>
#include "Ponto.h"
using namespace std;

double Ponto::getX() {
    return x;
}

double Ponto::getY() {
    return y;
}

void Ponto::setX(double x) {
    this->x = x;
}

void Ponto::setY(double y) {
    this->y = y;
}

void Ponto::imprimir() {
    cout << "(" << this->getX() << ", " << this->getY() << ")" << endl;
}

bool Ponto::eIgual(Ponto* outro) {
    if (this->getX() >= outro->getX() - 1e-5 && this->getX() <= outro->getX() + 1e-5)
        if (this->getY() >= outro->getY() - 1e-5 && this->getY() <= outro->getY() + 1e-5)
            return true;

    return false;
}
