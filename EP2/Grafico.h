#ifndef GRAFICO_H
#define GRAFICO_H

#include "Eixo.h"
#include "Serie.h"
#include "Tela.h"


class Grafico {
    private:
        Eixo* x;
        Eixo* y;
        Serie* serie;
    public:
        Grafico(Eixo* x, Eixo* y, Serie* serie);
        virtual ~Grafico();

        Eixo* getEixoX();
        Eixo* getEixoY();
        Serie* getSerie();

        /**
        * Desenha o Grafico na Tela.
        */
        void desenhar();
};

#endif // GRAFICO_H
