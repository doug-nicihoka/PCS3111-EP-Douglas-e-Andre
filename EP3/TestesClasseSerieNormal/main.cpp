#include <iostream>
#include <stdexcept>

#include "Ponto.h"
#include "Serie.h"
#include "SerieNormal.h"

using namespace std;

int main() {
    SerieNormal* sn = new SerieNormal("HIMYM", "Marshall", "Lily");

    /* Nome da s�rie */
    cout << "Serie: " << sn->getNome() << endl;
    cout << endl;

    /* Nome dos canais */
    cout << "Nome do canal X: " << sn->getNomeDoCanalX() << endl;
    cout << "Nome do canal Y: " << sn->getNomeDoCanalY() << endl << endl;

    /* Verificando se s�rie est� vazia e quantidade antes de adicionar */
    cout << (sn->estaVazia() ? "Serie vazia." : "Serie nao vazia.") << endl;
    cout << "Quantidade de pontos: " << sn->getQuantidade() << endl << endl;


    /* Testando erros dos m�todos getLimiteSuperior() e getLimiteInferior() */
    try {
        //sn->getLimiteSuperior(); //remover coment�rio para testar ambos os erros
        sn->getLimiteInferior();
    }
    catch (runtime_error *e) {
        cout << "Erro: " << e->what() << endl << endl;
        delete e;
    }

    /* Testando erro do m�todo getPosicao() com s�rie vazia */
    try {
        sn->getPosicao(0);
    }
    catch (out_of_range *e) {
        cout << "Erro: " << e->what() << endl << endl;
        delete e;
    }

    /* Adicionando pontos */
    sn->adicionar(10, -10);
    sn->imprimir();
    cout << "Quantidade de pontos: " << sn->getQuantidade() << endl << endl;

    sn->adicionar(0, 0);
    sn->imprimir();
    cout << "Quantidade de pontos: " << sn->getQuantidade() << endl << endl;

    sn->adicionar(10.0158, -10.0158);
    sn->imprimir();
    cout << "Quantidade de pontos: " << sn->getQuantidade() << endl << endl;

    sn->adicionar(-3.1415, 3.1415);
    sn->imprimir();
    cout << "Quantidade de pontos: " << sn->getQuantidade() << endl << endl;

    /* Verificando se s�rie est� vazia depois de adicionar */
    cout << (sn->estaVazia() ? "Serie vazia." : "Serie nao vazia.") << endl << endl;

    /* Obtendo limites superiores */
    cout << "Limite superior: "; sn->getLimiteSuperior()->imprimir();

    /* Obtendo limites inferiores */
    cout << "Limite inferior: "; sn->getLimiteInferior()->imprimir();
    cout << endl;

    /* Testando o metodo getPosi��o */
    for (int i = 0; i < sn->getQuantidade(); i++) {
        cout << "Ponto: "; sn->getPosicao(i)->imprimir();
        cout << "Posicao: " << i << endl << endl;
    }

    /* Testando erro do m�todo getPosicao() com s�rie n�o vazia */
    try {
        sn->getPosicao(4);
    }
    catch (out_of_range *e) {
        cout << "Erro: " << e->what() << endl << endl;
        delete e;
    }

    /* Deletando SerieNormal */
    delete sn;

    return 0;
}
