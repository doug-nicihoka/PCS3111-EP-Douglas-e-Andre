#include "Serie.h"
#include <iostream>
using namespace std;

void Serie::setNome(string nome) {
    this->nome = nome;
}

void Serie::setNomeDoCanalX(string nomeDoCanalX) {
    this->nomeDoCanalX = nomeDoCanalX;
}

void Serie::setNomeDoCanalY(string nomeDoCanalY) {
    this->nomeDoCanalY = nomeDoCanalY;
}

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
    Ponto* limiteSuperior = new Ponto;
    if (!estaVazia()) {
        double maiorX = eixoX[0];
        for (int i = 1; i < quantidade; i++)
            if (maiorX < eixoX[i])
                maiorX = eixoX[i];

        double maiorY = eixoY[0];
        for (int i = 1; i < quantidade; i++)
            if (maiorY < eixoY[i])
                maiorY = eixoY[i];

        limiteSuperior->setX(maiorX);
        limiteSuperior->setY(maiorY);

        return limiteSuperior;
    }
    return NULL;
}

Ponto* Serie::getLimiteInferior() {
    Ponto* limiteInferior = new Ponto;
    if (!estaVazia()) {
        double menorX = eixoX[0];
        for (int i = 1; i < quantidade; i++)
            if (menorX > eixoX[i])
                menorX = eixoX[i];

        double menorY = this->eixoY[0];
        for (int i = 1; i < quantidade; i++)
            if (menorY > eixoY[i])
                menorY = eixoY[i];

        limiteInferior->setX(menorX);
        limiteInferior->setY(menorY);

        return limiteInferior;
    }
    return NULL;
}

Ponto* Serie::getPosicao(int posicao) {
    if (posicao >= 0 && posicao < NUMERO_MAXIMO_VALORES) {
        Ponto* pontoPosicao = new Ponto;
        pontoPosicao->setX(eixoX[posicao]);
        pontoPosicao->setY(eixoY[posicao]);
        return pontoPosicao;
    }
    return NULL;
}

void Serie::imprimir() {
    cout << "Serie " << this->getNome() << endl;
    for(int i = 0; i < quantidade; i++) {
        cout << "(" << this->eixoX[i] << ", " << this->eixoY[i] << ")" << endl;
    }
}
