#include <iostream>
#include "Serie.h"
#include "Ponto.h"
#include "SerieTemporal.h"

using namespace std;

int main() {
    SerieTemporal *st = new SerieTemporal("Funcao", "Velocidade");
    cout << "Quantidade de pontos na serie " << st->getNome() << ": " << st->getQuantidade() << endl;
    st->adicionar(3);
    st->imprimir();
    st->adicionar(4);
    st->imprimir();
    st->adicionar(1, 5);
    st->imprimir();
    st->adicionar(3, 9);
    st->imprimir();
    st->adicionar(6);
    st->adicionar(0.5, 7);
    st->imprimir();
    return 0;
}
