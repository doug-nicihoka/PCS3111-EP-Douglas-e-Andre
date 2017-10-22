#include "EixoDinamico.h"

EixoDinamico::EixoDinamico(double minimoPadrao, double maximoPadrao, Serie* base, bool orientacaoHorizontal) :
    Eixo ("Vazio", minimoPadrao, maximoPadrao) {
    if (orientacaoHorizontal) {
        titulo = base->getNomeDoCanalX();
        if (base->getQuantidade() < 2 || base->getLimiteSuperior()->getX() - base->getLimiteInferior()->getX() <= 1e-5)
            return;

        else {
            minimo = base->getLimiteInferior()->getX();
            maximo = base->getLimiteSuperior()->getX();
        }
    }
    else {
        titulo = base->getNomeDoCanalY();
        if (base->getQuantidade() < 2 || base->getLimiteSuperior()->getY() - base->getLimiteInferior()->getY() <= 1e-5)
            return;

        else {
            minimo = base->getLimiteInferior()->getY();
            maximo = base->getLimiteSuperior()->getY();
        }
    }
}

EixoDinamico::~EixoDinamico() {}
