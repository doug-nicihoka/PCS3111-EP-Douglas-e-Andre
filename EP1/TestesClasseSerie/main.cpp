#include <iostream>
#include "Serie.h"
#include "Ponto.h"

using namespace std;

int main()
{
    Serie* s = new Serie;
    Ponto* upper;
    Ponto* lower;
    Ponto* posicao;

    /* Nomeando serie */
    s->setNome("HYMYM");
    cout << "Serie: " << s->getNome() << endl;
    cout << endl;

    /* Nomeando canais */
    s->setNomeDoCanalX("Marshall");
    cout << "Nome do canal X: " <<  s->getNomeDoCanalX() << endl;
    s->setNomeDoCanalY("Lily");
    cout << "Nome do canal Y: " << s->getNomeDoCanalY() <<endl << endl;

    /* Verificando quantidade e se serie esta vazia antes de adicionar */
    cout << "Quantidade de pontos: " << s->getQuantidade() << endl;
    if (s->estaVazia()) cout << "Serie vazia." << endl << endl;
    else cout << "Serie não vazia." << endl << endl;

    /* Verificando limites antes de adicionar */
    upper = s->getLimiteSuperior();
    if (upper == NULL) cout << "Sem limite superior." << endl;
    lower = s->getLimiteInferior();
    if (lower == NULL) cout << "Sem limite inferior." << endl;
    cout << endl;

    /* Adicionando pontos */
    s->adicionar(10, -10);
    s->imprimir(); cout << endl;

    s->adicionar(0, 0);
    s->imprimir(); cout << endl;

    s->adicionar(10.0158, -10.0158);
    s->imprimir(); cout << endl;

    s->adicionar(-3.1415, 3.1415);
    s->imprimir(); cout << endl;

    /* Verificando quantidade e se serie esta vazia depois de adicionar */
    cout << "Quantidade de pontos: " << s->getQuantidade() << endl;
    if (s->estaVazia()) cout << "Serie vazia." << endl << endl;
    else cout << "Serie nao vazia." << endl << endl;

    /* Obtendo limites superiores */
    upper = s->getLimiteSuperior();
    cout << "Limite superior: "; upper->imprimir();

    /* Obtendo limites inferiores */
    lower = s->getLimiteInferior();
    cout << "Limite inferior: "; lower->imprimir();
    cout << endl;

    /* Testando o metodo getQuantidade */
    for (int i = 0; i < s->getQuantidade(); i++) {
    posicao = s->getPosicao(i);
    cout << "Ponto: "; posicao->imprimir();
    cout << "Posicao: " << i << endl << endl;
    }

    return 0;
}
