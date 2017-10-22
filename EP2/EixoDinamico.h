#ifndef EIXODINAMICO_H
#define EIXODINAMICO_H

#include "Eixo.h"
#include "Serie.h"

class EixoDinamico : public Eixo {
    public:
        /**
        * Cria um EixoDinamico informando o m�nimo e o m�ximo padr�o,
        * a Serie que ser� usada como base e a orienta��o (true se for
        * horizontal e false se for vertical).
        */
        EixoDinamico(double minimoPadrao, double maximoPadrao, Serie* base, bool orientacaoHorizontal);
        virtual ~EixoDinamico();
};

#endif // EIXODINAMICO_H
