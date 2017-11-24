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

void PersistenciaDeSerie::inserir(std::string nome, Serie* s)
{
    std::string nomeNoArquivo, canalX, canalY;

    for (std::vector<std::string>::iterator it = nomesSeries->begin(); it != nomesSeries->end(); ++it) {
        if(*it == nome)
            throw new ErroDeArquivo("ERRO: Serie ja existente.");
    }
    std::ofstream out;
    out.open(arquivo, std::ios::app);
    out << nome << std::endl;
    if(s->getNomeDoCanalX() != "Tempo") {
        out << 1 << std::endl;
        out << s->getQuantidade() << std::endl;
        out << s->getNomeDoCanalX() << std::endl;
        out << s->getNomeDoCanalY() << std::endl;
        for (std::vector<Ponto*>::iterator it = s->getPontos()->begin(); it != s->getPontos()->end; ++it) {
                out << (*it)->getX() << std::endl;
                out << (*it)->getY() << std::endl;
        }
    }
    else {
        out << 0 << std::endl;
        out << s->getQuantidade() << std::endl;
        out << s->getNomeDoCanalY() << std::endl;
        for(std::vector<Ponto*>::iterator it = s->getPontos()->begin(); it != s->getPontos()->end; it++) {
                out << (*it)->getY() << std::endl;
        }
    }
}
