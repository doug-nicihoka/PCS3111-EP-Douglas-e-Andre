#ifndef EIXOESTATICO_H
#define EIXOESTATICO_H

#include "Eixo.h"


class EixoEstatico : public Eixo {
    public:
        /**
        * Cria um EixoEstatico informando o título, o mínimo, o máximo e
        * a orientação (true se for horizontal e false se for vertical).
        * @throw runtime_error caso o minimo >= maximo.
        */
        EixoEstatico(std::string titulo, double minimo, double maximo, bool orientacaoHorizontal);
        virtual ~EixoEstatico();
};

#endif // EIXOESTATICO_H
