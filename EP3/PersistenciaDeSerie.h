#ifndef PERSISTENCIADESERIE_H
#define PERSISTENCIADESERIE_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

#include "Serie.h"
#include "ErroDeArquivo.h"

using namespace std;

class PersistenciaDeSerie
{
    public:
        PersistenciaDeSerie(string arquivo);
        virtual ~PersistenciaDeSerie();
        Serie* obter(string nome);
        vector<string>* getNomes();
        void inserir(string nome, Serie* s);
    private:
        string arquivo;
        vector<string>* nomesSeries;
};

#endif // PERSISTENCIADESERIE_H
