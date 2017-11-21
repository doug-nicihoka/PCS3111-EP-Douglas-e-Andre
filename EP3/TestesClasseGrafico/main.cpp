#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>

#include "Ponto.h"
#include "Serie.h"
#include "SerieNormal.h"
#include "SerieTemporal.h"
#include "Grafico.h"
#include "Eixo.h"
#include "EixoEstatico.h"
#include "EixoDinamico.h"

using namespace std;

int main(){
    // Criando Eixos Estaticos para testes
    EixoEstatico* x = new EixoEstatico("EixoX", 0, 40, 1);
    EixoEstatico* y = new EixoEstatico("EixoY", 0, 39, 0);


    /*Teste com vector nulo */
    vector<Serie*>* series = nullptr;
    try {
        Grafico* g0 = new Grafico(x, y, series);
    }
    catch (logic_error *e) {
        cout << "Erro em 'Teste_0': " << e->what() << endl << endl;
        delete e;
    }


    /* Teste de eixos com orientação errada */
    series = new vector<Serie*>;
    try {
        // Mudar Eixos para testar
        Grafico* g1 = new Grafico(x, x, series);
    }
    catch (logic_error *e) {
        cout << "Erro em 'Teste_1': " << e->what() << endl << endl;
        delete e;
    }


    // Criando Series para proximo teste
    SerieNormal* s1 = new SerieNormal("Serie_1", "Temperatura", "Resistencia");
    SerieNormal* s2 = new SerieNormal("Serie_2", "Hora", "Luminosidade");
    SerieNormal* s3 = new SerieNormal("Serie_3", "Corrente", "Tensao");
    s1->adicionar(4, 28);
    s1->adicionar(7, 21);
    s2->adicionar(10, 15);
    s2->adicionar(12, 9);
    s3->adicionar(14,14);
    s3->adicionar(20, 3);
    s3->adicionar(27, 0);

    /* Teste do metodo desenhar */
    series->push_back(s1);
    series->push_back(s2);
    series->push_back(s3);
    Grafico* g2 = new Grafico(x, y, series);

    g2->desenhar();
    return 0;
}
