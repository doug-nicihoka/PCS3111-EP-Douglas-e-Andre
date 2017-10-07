#ifndef SERIETEMPORAL_H
#define SERIETEMPORAL_H
#define NUMERO_MAXIMO_VALORES 10

#include "Serie.h"


class SerieTemporal : public Serie {
    protected:
        double tempo = 1;
    public:
        /**
        * Cria uma SerieTemporal informando o nome da Serie e o nome do
        * canalY. O nome do canal X deve ser obrigatoriamente "Tempo".
        */
        SerieTemporal(string nome, string nomeDoCanalY);
        virtual ~SerieTemporal();

        /**
        * Adiciona um novo Ponto a Serie, no instante seguinte ao do
        * ponto anterior adicionado por este m�todo. O primeiro ponto
        * deve ser adicionado no instante 1.
        */
        virtual void adicionar(double valor);

        /**
        * Adiciona um Ponto a Serie informando a coordenada x e y.
        * Caso j� exista um ponto cuja coordenada x seja suficientemente
        * pr�xima ao do valor x informado, ao inv�s e adicionar o ponto,
        * altere o valor anterior (mantendo sua posi��o no arranjo)
        * ao considerar a nova coordenada y.
        * Caso a coordenada x do ponto for < 1, o ponto n�o deve ser adicionado.
        */
        virtual void adicionar(double x, double y);
};

#endif // SERIETEMPORAL_H
