#ifndef EIXO_H
#define EIXO_H

#include <string>

class Eixo {
    protected:
        std::string titulo;
        double minimo;
        double maximo;
        bool orientacaoHorizontal;
    public:
        /**
        * Cria um Eixo informando o t�tulo, o m�nimo, o m�ximo e
        * a orienta��o (true se for horizontal e false se for vertical).
        * @throw runtime_error caso o minimo >= maximo.
        */
        Eixo(std::string titulo, double minimo, double maximo, bool orientacaoHorizontal);
        virtual ~Eixo() = 0;

        virtual std::string getTitulo();
        virtual double getMinimo();
        virtual double getMaximo();
        virtual bool temOrientacaoHorizontal();
};

#endif // EIXO_H
