#include "PersistenciaDeSerie.h"

PersistenciaDeSerie::PersistenciaDeSerie(string arquivo) : arquivo (arquivo) {
    nomesSeries = new vector<string>();
    string nomeNoArquivo, canalX, canalY;
    bool tipoSerie;
    int quantidadePontos;
    double x, y;
    ifstream in;
    in.open(arquivo);
    while(!in.eof()) {
        in >> nomeNoArquivo >> tipoSerie >> quantidadePontos;
        if(in.fail()) {
            throw new ErroDeArquivo("Erro: arquivo no formato errado");
        }
        nomesSeries->push_back(nomeNoArquivo);
        if(tipoSerie == 1) {
            in >> canalX, canalY;
            if(in.fail()) {
                throw new ErroDeArquivo("Erro: arquivo no formato errado");
            }
            for(int i = 0; i < quantidadePontos; i++) {
                in >> x >> y;
                if(in.fail()) {
                    throw new ErroDeArquivo("Erro: arquivo no formato errado");
                }
            }
        }
        else if(tipoSerie == 0) {
            in >> canalY;
            if(in.fail()) {
                throw new ErroDeArquivo("Erro: arquivo no formato errado");
            }
            for(int j = 0; j < quantidadePontos; j++) {
                in >> y;
                if(in.fail()) {
                    throw new ErroDeArquivo("Erro: arquivo no formato errado");
                }
            }
        }
    }
}

PersistenciaDeSerie::~PersistenciaDeSerie() {
    delete nomesSeries;
}

Serie* PersistenciaDeSerie::obter(string nome)
{
    string nomeNoArquivo, canalX,canalY;
    bool tipoSerie;
    int quantidadePontos;
    double x, y;
    ifstream in;
    in.open(arquivo);
    while(!in.eof()) {
        in >> nomeNoArquivo >> tipoSerie >> quantidadePontos;
        if(tipoSerie) {
            in >> canalX >> canalY;
            for(int i = 0; i < quantidadePontos; i++) {
                in >> x >> y;
            }
        }
        else if(!tipoSerie) {
            in >> canalY;
            for(int j = 0; j < quantidadePontos; j++) {
                in >> y;
            }
        }
        if(nome == nomeNoArquivo) {
            Serie *serieBuscada = new Serie(nomeDoArquivo, canalXDoArquivo, canalYDoArquivo);
            return serieBuscada;
        }
    }
    return NULL;
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
