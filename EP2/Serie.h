#ifndef SERIE_H
#define SERIE_H

#define NUMERO_MAXIMO_VALORES 10

#include <string>
#include "Ponto.h"

class Serie {
    protected:
        std::string nome, nomeDoCanalX, nomeDoCanalY;
        double eixoX[NUMERO_MAXIMO_VALORES], eixoY[NUMERO_MAXIMO_VALORES];
        int quantidade = 0;
    public:
        /**
        * Cria uma Serie informando o nome dela e o nome dos canais X e Y.
        */
        Serie(std::string nome, std::string nomeDoCanalX, std::string nomeDoCanalY);
        virtual ~Serie();

        // Permite obter o nome, o nomeDoCanalX e o nomeDoCanalY.
        virtual std::string getNome();
        virtual std::string getNomeDoCanalX();
        virtual std::string getNomeDoCanalY();

        /**
        * Informa a quantidade de pontos que a Serie possui.
        */
        virtual int getQuantidade();

        /**
        * Informa se a Serie esta vazia.
        */
        virtual bool estaVazia();

        /**
        * Adiciona um novo ponto a Serie, informando sua coordenada x e y.
        * Ignora o valor passado caso o NUMERO_MAXIMO_VALORES tenha
        * sido ultrapassado.
        */
        virtual void adicionar(double x, double y);

        /**
        * Obtem um ponto representando o limite superior da Serie.
        * A coordenada x desse ponto deve ser o maximo valor horizontal
        * existente na Serie e a coordenada y deve ser o maximo valor
        * vertical existente na Serie.
        *
        * Caso a Serie nao tenha valores, deve-se retornar NULL.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)} o limite
        * superior eh (5, 3).
        */
        virtual Ponto* getLimiteSuperior();

        /**
        * Obtem um ponto representando o limite inferior da Serie.
        * A coordenada x desse ponto deve ser o minimo valor horizontal
        * existente na Serie e a coordenada y deve ser o minimo valor
        * vertical existente na Serie.
        *
        * Caso a serie nao tenha valores, deve-se retornar NULL.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)} o limite
        * inferior eh (1, 1).
        */
        virtual Ponto* getLimiteInferior();

        /**
        * Obtem o ponto que esta na posicao definida da Serie. A contagem de
        * posicoes comeca em 0.
        *
        * Em caso de posicoes invalidas, retorne NULL.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)}, getPosicao(0)
        * deve retornar (2, 3) e getPosicao(2) deve retornar (1, 2).
        */
        virtual Ponto* getPosicao(int posicao);

        /**
        * Imprime na saida padrao (cout) o nome da Serie e seus pontos
        * seguindo o formato definido.
        */
        virtual void imprimir();
};

#endif // SERIE_H
