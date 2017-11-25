#include "Grafico.h"
#include "Tela.h"
#include <stdexcept>

Grafico::Grafico(Eixo* x, Eixo* y, std::vector<Serie*>* series) : x (x), y (y), series (series) {
    if (!x->temOrientacaoHorizontal())
        throw new std::logic_error ("ERRO: Eixo x com orientacao vertical.");
    else if (y->temOrientacaoHorizontal())
        throw new std::logic_error ("ERRO: Eixo y com orientacao horizontal.");
    else if (!series)
        throw new std::logic_error ("ERRO: vector de Series nulo.");
}

Grafico::~Grafico() {}

Eixo* Grafico::getEixoX() {
    return x;
}

Eixo* Grafico::getEixoY() {
    return y;
}

std::vector<Serie*>* Grafico::getSeries() {
    return series;
}

void Grafico::desenhar() {
    Tela* t = new Tela;
    t->setEixoX(x->getTitulo(), x->getMinimo(), x->getMaximo());
    t->setEixoY(y->getTitulo(), y->getMinimo(), y->getMaximo());

    // Iterator da Serie
    std::vector<Serie*>::iterator sIt;
    // Iterator do Ponto
    std::vector<Ponto*>::iterator pIt;
    for (sIt = series->begin(); sIt != series->end(); ++sIt)
        for(pIt = (*sIt)->getPontos()->begin(); pIt != (*sIt)->getPontos()->end(); ++pIt)
            t->plotar((*sIt)->getNome(), (*pIt)->getX(), (*pIt)->getY());


    t->mostrar();
    delete t;
}
