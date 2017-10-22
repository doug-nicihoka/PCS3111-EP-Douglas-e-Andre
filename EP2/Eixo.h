#ifndef EIXO_H
#define EIXO_H

#include <string>

class Eixo {
    protected:
        std::string titulo;
        double minimo;
        double maximo;
    public:
        /**
        * Cria um Eixo informando o t�tulo, o m�nimo e o m�ximo.
        */
        Eixo(std::string titulo, double minimo, double maximo);
        virtual ~Eixo();

        virtual std::string getTitulo();
        virtual double getMinimo();
        virtual double getMaximo();
};

#endif // EIXO_H
