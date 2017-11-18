#ifndef EIXODINAMICO_H
#define EIXODINAMICO_H

#include <list>
#include "Eixo.h"
#include "Serie.h"

class EixoDinamico : public Eixo {
    public:
        /**
        * Cria um EixoDinamico informando o mínimo e o máximo
        * padrão, a lista de Series que devem ser consideradase a orientação
        * (true se for horizontal e false se for vertical).
        * @throw runtime_error caso o minimoPadrao >= maximoPadrao.
        */
        EixoDinamico(std::string titulo, double minimoPadrao, double maximoPadrao, std::list<Serie*>* series, bool orientacaoHorizontal);
        virtual ~EixoDinamico();
};

#endif // EIXODINAMICO_H
