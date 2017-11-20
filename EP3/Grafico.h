#ifndef GRAFICO_H
#define GRAFICO_H

#include "Eixo.h"
#include "Serie.h"
#include "Tela.h"

class Grafico {
    private:
        Eixo* x;
        Eixo* y;
        std::vector<Serie*>* series;
    public:
        /**
        * Cria um Grafico informando os Eixos e as Series.
        * @throw logic_error caso o eixo x n�o tenha orienta��o horizontal ou
        * o eixo y n�o tenha orienta��o vertical.
        */
        Grafico(Eixo* x, Eixo* y, vector<Serie*>* series);
        virtual ~Grafico();

        Eixo* getEixoX();
        Eixo* getEixoY();
        std::vector<Serie*>* getSeries();

        /**
        * Desenha o Grafico na Tela.
        */
        void desenhar();
};

#endif // GRAFICO_H
