#include "EixoDinamico.h"
#include <stdexcept>

EixoDinamico::EixoDinamico(std::string titulo, double minimoPadrao, double maximoPadrao, std::list<Serie*>* series, bool orientacaoHorizontal) :
    Eixo (titulo, minimoPadrao, maximoPadrao, orientacaoHorizontal) {
    if (series) {                                                               //Se o ponteiro series não é nulo
        if (!series->empty()) {                                                 //Se a lista para qual o ponteiro aponta não está vazia
            std::list<Serie*>::iterator it;
            double min, max;
            int aux = 0;
            for (it = series->begin(); it != series->end(); ++it) {             // Varre a lista inteira
                if (!(*it)->estaVazia()) {                                      // Se sair do loop sem entrar nenhuma vez aqui, lista possui Series vazias
                    if (orientacaoHorizontal) {                                 // Eixo horizontal
                        if (aux == 0) {                                         // Detecta a primeira vez em que se entra na condição da linha 12
                            max = (*it)->getLimiteSuperior()->getX();
                            min = (*it)->getLimiteInferior()->getX();
                            ++aux;
                        }
                        else {                                                  // Começa a comparar com valores guardados nas variáveis min e max
                            if (max < (*it)->getLimiteSuperior()->getX())
                                max = (*it)->getLimiteSuperior()->getX();

                            if (min > (*it)->getLimiteInferior()->getX())
                                min = (*it)->getLimiteInferior()->getX();
                        }
                    }
                    else {                                                      // Eixo vertical (análogo ao eixo horizontal)
                        if (aux == 0) {
                            max = (*it)->getLimiteSuperior()->getY();
                            min = (*it)->getLimiteInferior()->getY();
                            ++aux;
                        }
                        else {
                            if (max < (*it)->getLimiteSuperior()->getY())
                                max = (*it)->getLimiteSuperior()->getY();

                            if (min > (*it)->getLimiteInferior()->getY())
                                min = (*it)->getLimiteInferior()->getY();
                        }
                    }
                }
            }
            if (aux != 0) {                                                     // Só entra aqui caso a lista possua pelo menos uma Serie não vazia.
                if (max - min > 1e-5) {
                    maximo = max;
                    minimo = min;
                }
            }
        }
    }
    else throw new std::logic_error ("ERRO: list de Series nula.");
}

EixoDinamico::~EixoDinamico() {}
