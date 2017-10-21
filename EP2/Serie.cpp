#include "Serie.h"
#include <iostream>
using namespace std;

Serie::Serie(string nome, string nomeDoCanalX, string nomeDoCanalY) :
    nome (nome), nomeDoCanalX (nomeDoCanalX), nomeDoCanalY (nomeDoCanalY) {}

Serie::~Serie() {}


string Serie::getNome() {
    return nome;
}

string Serie::getNomeDoCanalX() {
    return nomeDoCanalX;
}

string Serie::getNomeDoCanalY() {
    return nomeDoCanalY;
}

int Serie::getQuantidade() {
    return quantidade;
}

bool Serie::estaVazia() {
    if (quantidade == 0)
        return true;
    return false;
}

void Serie::adicionar(double x, double y) {
   if (quantidade < NUMERO_MAXIMO_VALORES) {
        eixoX[quantidade] = x;
        eixoY[quantidade] = y;
        quantidade++;
   }
}

Ponto* Serie::getLimiteSuperior() {
    if (!estaVazia()) {
        double maiorX = eixoX[0];
        for (int i = 1; i < quantidade; i++)
            if (maiorX < eixoX[i])
                maiorX = eixoX[i];

        double maiorY = eixoY[0];
        for (int i = 1; i < quantidade; i++)
            if (maiorY < eixoY[i])
                maiorY = eixoY[i];

        Ponto* limiteSuperior = new Ponto(maiorX, maiorY);
        return limiteSuperior;
    }
    return NULL;
}

Ponto* Serie::getLimiteInferior() {
    if (!estaVazia()) {
        double menorX = eixoX[0];
        for (int i = 1; i < quantidade; i++)
            if (menorX > eixoX[i])
                menorX = eixoX[i];

        double menorY = eixoY[0];
        for (int i = 1; i < quantidade; i++)
            if (menorY > eixoY[i])
                menorY = eixoY[i];

        Ponto* limiteInferior = new Ponto(menorX, menorY);
        return limiteInferior;
    }
    return NULL;
}

Ponto* Serie::getPosicao(int posicao) {
    if (posicao >= 0 && posicao < quantidade) {
        Ponto* pontoPosicao = new Ponto(eixoX[posicao], eixoY[posicao]);
        return pontoPosicao;
    }
    return NULL;
}

void Serie::imprimir() {
    cout << "Serie " << getNome() << endl;
    for(int i = 0; i < quantidade; i++)
        cout << "(" << eixoX[i] << ", " << eixoY[i] << ")" << endl;
}
