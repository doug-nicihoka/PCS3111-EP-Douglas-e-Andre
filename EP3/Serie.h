#ifndef SERIE_H
#define SERIE_H

#define NUMERO_MAXIMO_VALORES 10

#include <string>
#include <vector>
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
        // Fa�a o destrutor ser abstrato (puramente virtual)
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
        * Obt�m todos os pontos da Serie.
        */
        virtual std::vector<Ponto*>* getPontos();

        /**
        * Obt�m um ponto representando o limite superior da Serie.
        * A coordenada x desse ponto deve ser o m�ximo valor horizontal
        * existente na Serie e a coordenada y deve ser o m�ximo valor
        * vertical existente na Serie.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)} o limite
        * superior � (5, 3).
        * @throw runtime_error caso a Serie n�o tenha valores.
        */
        virtual Ponto* getLimiteSuperior();

        /**
        * Obt�m um ponto representando o limite inferior da Serie.
        * A coordenada x desse ponto deve ser o m�nimo valor horizontal
        * existente na Serie e a coordenada y deve ser o m�nimo valor
        * vertical existente na Serie.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)} o limite
        * inferior � (1, 1).
        * @throw runtime_error caso a Serie n�o tenha valores.
        */
        virtual Ponto* getLimiteInferior();

        /**
        * Obt�m o ponto que est� na posi��o definida da Serie. A contagem de
        * posi��es come�a em 0.
        *
        * Por exemplo, para a Serie {(2, 3), (5, 1), (1, 2)}, getPosicao(0)
        * deve retornar (2, 3) e getPosicao(2) deve retornar (1, 2).
        * @throw out_of_range caso a posi��o seja inv�lida.
        */
        virtual Ponto* getPosicao(int posicao);

        /**
        * Imprime na saida padrao (cout) o nome da Serie e seus pontos
        * seguindo o formato definido.
        */
        virtual void imprimir();
};

#endif // SERIE_H
