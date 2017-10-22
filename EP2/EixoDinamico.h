#ifndef EIXODINAMICO_H
#define EIXODINAMICO_H

#include "Eixo.h"
#include "Serie.h"

class EixoDinamico : public Eixo {
    public:
        /**
        * Cria um EixoDinamico informando o mínimo e o máximo padrão,
        * a Serie que será usada como base e a orientação (true se for
        * horizontal e false se for vertical).
        */
        EixoDinamico(double minimoPadrao, double maximoPadrao, Serie* base, bool orientacaoHorizontal);
        virtual ~EixoDinamico();
};

#endif // EIXODINAMICO_H
