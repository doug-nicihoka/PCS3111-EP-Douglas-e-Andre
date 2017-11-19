#ifndef SERIETEMPORAL_H
#define SERIETEMPORAL_H

#include "Serie.h"

class SerieTemporal : public Serie {
    protected:
        double tempo = 1;
    public:
        /**
        * Cria uma SerieTemporal informando o nome da Serie e o nome do
        * canalY. O nome do canalX deve ser obrigatoriamente "Tempo".
        */
        SerieTemporal(std::string nome, std::string nomeDoCanalY);
        virtual ~SerieTemporal();

        /**
        * Adiciona um novo Ponto à Serie, no instante seguinte ao do
        * ponto anterior. O primeiro ponto deve ser adicionado no instante 1.
        */
        virtual void adicionar(double valor);
};

#endif // SERIETEMPORAL_H
