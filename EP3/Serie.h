#ifndef SERIE_H
#define SERIE_H

#include <string>
#include <vector>
#include "Ponto.h"

class Serie {
    protected:
        std::string nome, nomeDoCanalX, nomeDoCanalY;
        std::vector<Ponto*>* pontos;
    public:
        /**
        * Cria uma Serie informando o nome dela e o nome dos canais X e Y.
        */
        Serie(std::string nome, std::string nomeDoCanalX, std::string nomeDoCanalY);
        // Faça o destrutor ser abstrato (puramente virtual)
        virtual ~Serie() = 0;

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
        * Obtém todos os pontos da Serie.
        */
        virtual std::vector<Ponto*>* getPontos();

        /**
        * Obtém um ponto representando o limite superior da Serie.
        * A coordenada x desse ponto deve ser o máximo valor horizontal
        * existente na Serie e a coordenada y deve ser o máximo valor
        * vertical existente na Serie.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)} o limite
        * superior é (5, 3).
        * @throw runtime_error caso a Serie não tenha valores.
        */
        virtual Ponto* getLimiteSuperior();

        /**
        * Obtém um ponto representando o limite inferior da Serie.
        * A coordenada x desse ponto deve ser o mínimo valor horizontal
        * existente na Serie e a coordenada y deve ser o mínimo valor
        * vertical existente na Serie.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)} o limite
        * inferior é (1, 1).
        * @throw runtime_error caso a Serie não tenha valores.
        */
        virtual Ponto* getLimiteInferior();

        /**
        * Obtém o ponto que está na posição definida da Serie. A contagem de
        * posições começa em 0.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)}, getPosicao(0)
        * deve retornar (2, 3) e getPosicao(2) deve retornar (1, 2).
        * @throw out_of_range caso a posição seja inválida.
        */
        virtual Ponto* getPosicao(int posicao);

        /**
        * Imprime na saida padrao (cout) o nome da Serie e seus pontos
        * seguindo o formato definido.
        */
        virtual void imprimir();
};

#endif // SERIE_H
