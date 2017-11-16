#include "Serie.h"

#include <iostream>
#include  <stdexcept>

using namespace std;

Serie::Serie(string nome, string nomeDoCanalX, string nomeDoCanalY) : nome (nome), nomeDoCanalX (nomeDoCanalX), nomeDoCanalY (nomeDoCanalY) {
    pontos = new vector<Ponto*>();
}

Serie::~Serie() {
    for (unsigned int i = 0; i < pontos->size(); i++)
        delete pontos->at(i);
    pontos->clear();
    delete pontos;
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
    return pontos->size();
}

bool Serie::estaVazia() {
    return pontos->empty();
}

vector<Ponto*>* Serie::getPontos() {
    return pontos;
}

Ponto* Serie::getLimiteSuperior() {
    if (!estaVazia()) {
        double maiorX = pontos->at(0)->getX();
        for (unsigned int i = 0; i < pontos->size(); i++)
            if (maiorX < pontos->at(i)->getX())
                maiorX = pontos->at(i)->getX();

        double maiorY = pontos->at(0)->getY();
        for (unsigned int i = 0; i < pontos->size(); i++)
            if (maiorY < pontos->at(i)->getY())
                maiorY = pontos->at(i)->getY();

        return new Ponto(maiorX, maiorY);
    }
    throw new runtime_error ("Sem limite superior.");
}

Ponto* Serie::getLimiteInferior() {
    if (!estaVazia()) {
        double menorX = pontos->at(0)->getX();
        for (unsigned int i = 0; i < pontos->size(); i++)
            if (menorX > pontos->at(i)->getX())
                menorX = pontos->at(i)->getX();

        double menorY = pontos->at(0)->getY();
        for (unsigned int i = 0; i < pontos->size(); i++)
            if (menorY > pontos->at(i)->getY())
                menorY = pontos->at(i)->getY();

        return new Ponto(menorX, menorY);
    }
    throw new runtime_error ("Sem limite inferior.");
}

Ponto* Serie::getPosicao(int posicao) {
    if (posicao >= 0 && posicao < pontos->size()) {
        return pontos->at(posicao);
    }
    throw new out_of_range ("Posicao invalida.");
}

void Serie::imprimir() {
    cout << "Serie " << getNome() << endl;
    for (unsigned int i = 0; i < pontos->size(); i++)
        cout << "(" << pontos->at(i)->getX() << ", " << pontos->at(i)->getY() << ")" << endl;
}
