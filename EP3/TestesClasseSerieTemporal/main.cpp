#include <iostream>
#include <stdexcept>

#include "Ponto.h"
#include "Serie.h"
#include "SerieTemporal.h"

using namespace std;

int main() {
    SerieTemporal* st = new SerieTemporal("Grafico", "Velocidade");

    /* Nome da série */
    cout << "Serie: " << st->getNome() << endl;
    cout << endl;

    /* Nome dos canais */
    cout << "Nome do canal X: " << st->getNomeDoCanalX() << endl;
    cout << "Nome do canal Y: " << st->getNomeDoCanalY() << endl << endl;

    /* Verificando se série está vazia e quantidade antes de adicionar */
    cout << (st->estaVazia() ? "Serie vazia." : "Serie nao vazia.") << endl;
    cout << "Quantidade de pontos: " << st->getQuantidade() << endl << endl;


    /* Testando erros dos métodos getLimiteSuperior() e getLimiteInferior() */
    try {
        //st->getLimiteSuperior(); //remover comentário para testar ambos os erros
        st->getLimiteInferior();
    }
    catch (runtime_error *e) {
        cout << "Erro: " << e->what() << endl << endl;
        delete e;
    }

    /* Testando erro do método getPosicao() com série vazia */
    try {
        st->getPosicao(0);
    }
    catch (out_of_range *e) {
        cout << "Erro: " << e->what() << endl << endl;
        delete e;
    }

    /* Adicionando pontos */
    st->adicionar(10);
    st->imprimir();
    cout << "Quantidade de pontos: " << st->getQuantidade() << endl << endl;

    st->adicionar(0);
    st->imprimir();
    cout << "Quantidade de pontos: " << st->getQuantidade() << endl << endl;

    st->adicionar(-12.4);
    st->imprimir();
    cout << "Quantidade de pontos: " << st->getQuantidade() << endl << endl;

    st->adicionar(-3.1415);
    st->imprimir();
    cout << "Quantidade de pontos: " << st->getQuantidade() << endl << endl;

    /* Verificando se série está vazia depois de adicionar */
    cout << (st->estaVazia() ? "Serie vazia." : "Serie nao vazia.") << endl << endl;

    /* Obtendo limites superiores */
    cout << "Limite superior: "; st->getLimiteSuperior()->imprimir();

    /* Obtendo limites inferiores */
    cout << "Limite inferior: "; st->getLimiteInferior()->imprimir();
    cout << endl;

    /* Testando o metodo getPosição */
    for (int i = 0; i < st->getQuantidade(); i++) {
        cout << "Ponto: "; st->getPosicao(i)->imprimir();
        cout << "Posicao: " << i << endl << endl;
    }

    /* Testando erro do método getPosicao() com série não vazia */
    try {
        st->getPosicao(4);
    }
    catch (out_of_range *e) {
        cout << "Erro: " << e->what() << endl << endl;
        delete e;
    }

    /* Deletando SerieNormal */
    delete st;

    return 0;
}
