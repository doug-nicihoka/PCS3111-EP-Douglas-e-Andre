#ifndef SERIENORMAL_H
#define SERIENORMAL_H

#include "Serie.h"


class SerieNormal : public Serie {
    public:
        SerieNormal(std::string nome, std::string nomeDoCanalX, std::string nomeDoCanalY);
        virtual ~SerieNormal();

        /**
        * Adiciona um novo ponto à Serie, informando sua coordenada x e y.
        */
        virtual void adicionar (double x, double y);
};

#endif // SERIENORMAL_H
