#ifndef GRAFICO_H
#define GRAFICO_H

#include <string>
#include "Eixo.h"
#include "Serie.h"
#include "Tela.h"

class Eixo {
    protected:
        Eixo* x;
        Eixo* y;
        Serie* Serie;
    public:
        /**
        * Cria um grafico informando os eixos e a serie.
        */
        Grafico(Eixo* x, Eixo* y, Serie* Serie);
        virtual ~Grafico();

        Eixo* getEixoX();
        Eixo* getEixoY();
        Serie* getSerie();
        /**
        * Desenha o grafico na tela.
        */
};

#endif // EIXO_H
