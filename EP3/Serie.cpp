#include "Serie.h"

#include <iostream>
#include  <stdexcept>

using namespace std;

Serie::Serie(string nome, string nomeDoCanalX, string nomeDoCanalY) : nome (nome), nomeDoCanalX (nomeDoCanalX), nomeDoCanalY (nomeDoCanalY) {
    pontos = new vector<Ponto*>();
}

Serie::~Serie() {
    vector<Ponto*>::iterator it;
    for (it = pontos->begin(); it != pontos->end(); ++it)
        delete *it;
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
        vector<Ponto*>::iterator it;
        for (it = pontos->begin(); it != pontos->end(); ++it)
            if (maiorX < (*it)->getX())
                maiorX = (*it)->getX();

        double maiorY = pontos->at(0)->getY();
        for (it = pontos->begin(); it != pontos->end(); ++it)
            if (maiorY < (*it)->getY())
                maiorY = (*it)->getY();

        return new Ponto(maiorX, maiorY);
    }
    throw new runtime_error ("Sem limite superior.");
}

Ponto* Serie::getLimiteInferior() {
    if (!estaVazia()) {
        double menorX = pontos->at(0)->getX();
        vector<Ponto*>::iterator it;
        for (it = pontos->begin(); it != pontos->end(); ++it)
            if (menorX > (*it)->getX())
                menorX = (*it)->getX();

        double menorY = pontos->at(0)->getY();
        for (it = pontos->begin(); it != pontos->end(); ++it)
            if (menorY > (*it)->getY())
                menorY = (*it)->getY();

        return new Ponto(menorX, menorY);
    }
    throw new runtime_error ("Sem limite inferior.");
}

Ponto* Serie::getPosicao(int posicao) {
    int tam = pontos->size();
    if (posicao >= 0 && posicao < tam) {
        return pontos->at(posicao);
    }
    throw new out_of_range ("Posicao invalida.");
}

void Serie::imprimir() {
    cout << "Serie " << getNome() << endl;
    vector<Ponto*>::iterator it;
    for (it = pontos->begin(); it != pontos->end(); ++it)
        cout << "(" << (*it)->getX() << ", " << (*it)->getY() << ")" << endl;
}
