#include "PersistenciaDeSerie.h"
#include "ErroDeArquivo.h"
#include "SerieNormal.h"
#include "SerieTemporal.h"
#include <fstream>

PersistenciaDeSerie::PersistenciaDeSerie(std::string arquivo) : arquivo (arquivo) {
    nomesSeries = new std::vector<std::string>;

    std::string nome, canalX, canalY;
    bool tipoSerie;
    int quantidade;
    double x, y;

    std::ifstream in;
    in.open(arquivo);

    while(!in.eof()) {
        in >> nome >> tipoSerie >> quantidade;
        if(in.fail()) {
            throw new ErroDeArquivo("ERRO: arquivo com formato errado.");
        }
        nomesSeries->push_back(nome);
        if(tipoSerie) {
            in >> canalX >> canalY;
            if(in.fail()) {
                throw new ErroDeArquivo("ERRO: arquivo com formato errado.");
            }
            for(int i = 0; i < quantidade; ++i) {
                in >> x >> y;
                if(in.fail()) {
                    throw new ErroDeArquivo("ERRO: arquivo com formato errado.");
                }
            }
        }
        else if(!tipoSerie) {
            in >> canalY;
            if(in.fail()) {
                throw new ErroDeArquivo("ERRO: arquivo com formato errado.");
            }
            for(int i = 0; i < quantidade; ++i) {
                in >> y;
                if(in.fail()) {
                    throw new ErroDeArquivo("ERRO: arquivo com formato errado.");
                }
            }
        }
    }
}

PersistenciaDeSerie::~PersistenciaDeSerie() {
    delete nomesSeries;
}

Serie* PersistenciaDeSerie::obter(std::string nome)
{
    std::string nomeNoArquivo, canalX,canalY;
    bool tipoSerie;
    int quantidade;
    double x, y;

    std::ifstream in;
    in.open(arquivo);

    while(!in.eof()) {
        in >> nomeNoArquivo >> tipoSerie >> quantidade;
        if(nomeNoArquivo == nome) {
            if(tipoSerie) {
                in >> canalX >> canalY;
                SerieNormal* sn = new SerieNormal(nomeNoArquivo, canalX, canalY);
                for(int i = 0; i < quantidade; ++i) {
                    in >> x >> y;
                    sn->adicionar(x, y);
                }
                return sn;
            }
            else {
                in >> canalY;
                SerieTemporal* st = new SerieTemporal(nomeNoArquivo, canalY);
                for(int i = 0; i < quantidade; ++i) {
                    in >> y;
                    st->adicionar(y);
                }
                return st;
            }
        }
        else {
            if(tipoSerie) {
                in >> canalX >> canalY;
                for(int i = 0; i < quantidade; ++i) {
                    in >> x >> y;
                }
            }
            else if(!tipoSerie) {
                in >> canalY;
                for(int i = 0; i < quantidade; ++i) {
                    in >> y;
                }
            }
        }
    }
    return nullptr;
}

vector<string>* PersistenciaDeSerie::getNomes()
{
    return nomesSeries;
}

void PersistenciaDeSerie::inserir(string nome, Serie* s)
{
    string nomeNoArquivo, canalX, canalY;
    bool tipoSerie;
    int quantidadePontos;
    double x, y;
    for (vector<string>::iterator it = nomesSeries->begin(); it = nomesSeries->end(); ++it) {
        if((*it)->getNome == nome)
            throw new ErroDeArquivo("Erro: serie ja existente");
    }
    ofstream out;
    out.open(arquivo);
    out << nome << endl;
    if(s->getNomeDoCanalX() != "Tempo") {
        out << 1 << endl;
        out << s->getQuantidade() << endl;
        out << s->getNomeDoCanalX() << endl;
        out << s->getNomeDoCanalY() << endl;
        vector<Ponto*>::iterator it;
        for(it = s->getPontos()->begin(); it != s->getPontos()->end; it++) {
                out << (*it)->getX();
                out << (*it)->getY();
        }
    }
    else {
        out << 0 << endl;
        out << s->getQuantidade() << endl;
        out << s->getNomeDoCanalY() << endl;
        vector<Ponto*>::iterator it;
        for(it = s->getPontos()->begin(); it != s->getPontos()->end; it++) {
                out << (*it)->getY();
        }
    }
}
