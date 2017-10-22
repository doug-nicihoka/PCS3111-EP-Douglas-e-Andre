#include "Grafico.h"

Grafico::Grafico(Eixo* x, Eixo* y, Serie* serie) :
    x (x), y (y), serie (serie) {}

Grafico::~Grafico() {
    delete x;
    delete y;
    delete serie;
}

Eixo* Grafico::getEixoX() {
    return x;
}

Eixo* Grafico::getEixoY() {
    return y;
}

Eixo* Grafico::getSerie() {
    return serie;
}

void Grafico::desenhar() {
    Tela* t = new Tela;
    t->setEixoX(x->getTitulo(), x->getMinimo(), x->getMaximo());
    t->setEixoY(y->getTitulo(), y->getMinimo(), y->getMaximo());
    
    for (int i = 0; i < serie->getQuantidade(); i++)
        t->plotar(serie->getNome(), serie->getPosicao(i)->getX(), serie->getPosicao(i)->getY());
    
    t->mostrar();
    delete t;
}
