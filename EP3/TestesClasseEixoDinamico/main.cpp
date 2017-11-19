#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include "Eixo.h"
#include "EixoDinamico.h"
#include "Serie.h"
#include "SerieTemporal.h"
#include "SerieNormal.h"
#include "Ponto.h"
#include "InterfaceSerial.h"
using namespace std;

int main()
{
    /* Teste com lista nula */
    list<Serie*>* series = nullptr;
    try {
    EixoDinamico *ed0 = new EixoDinamico("Teste_0", -72.135, 200.124, series, 1);
    }
    catch (logic_error *e) {
    cout << "Erro em 'Teste_0': " << e->what() << endl << endl;
    delete e;
    }


    /* Teste com lista vazia */
    series = new list<Serie*>;
    EixoDinamico *ed1 = new EixoDinamico("Teste_1", -72.135, 200.124, series, 1);
    cout << "Titulo do eixo: " << ed1->getTitulo() << endl;
    cout << "    Minimo: " << ed1->getMinimo() << endl;
    cout << "    Maximo: " << ed1->getMaximo() << endl;
    cout << "    Orientacao: " << (ed1->temOrientacaoHorizontal() ? "Horizontal" : "Vertical") << endl << endl;


    // Criando series
    SerieNormal* s1 = new SerieNormal("Serie_1", "Temperatura", "Resistencia");
    SerieNormal* s2 = new SerieNormal("Serie_2", "Hora", "Luminosidade");
    SerieNormal* s3 = new SerieNormal("Serie_3", "Corrente", "Tensao");
    series->push_back(s1);
    series->push_back(s2);
    series->push_back(s3);

    /* Teste de lista com Series vazias */
    EixoDinamico *ed2 = new EixoDinamico("Teste_2", -89.1, 145.8, series, 0);
    cout << "Titulo do eixo: " << ed2->getTitulo() << endl;
    cout << "    Minimo: " << ed2->getMinimo() << endl;
    cout << "    Maximo: " << ed2->getMaximo() << endl;
    cout << "    Orientacao: " << (ed2->temOrientacaoHorizontal() ? "Horizontal" : "Vertical") << endl << endl;


    // Adicionando series nao vazias a lista
    s1->adicionar(1,-10);
    s1->adicionar(2,13);
    s1->adicionar(4,12);
    s1->adicionar(53,20);
    s2->adicionar(-2,198);
    s2->adicionar(100,25);
    s2->adicionar(-11,-17);
    s2->adicionar(10,21);
    s2->adicionar(-151,-53);
    s3->adicionar(-45,-42);
    s3->adicionar(2,20);
    s3->adicionar(0.0001,87);
    series->push_back(s1);
    series->push_back(s2);
    series->push_back(s3);

    /* Teste com lista de Series nao vazias */
    EixoDinamico *ed3 = new EixoDinamico("Teste_3", 12.9, 52.12, series, 0);
    cout << "Titulo do eixo: " << ed3->getTitulo() << endl;
    cout << "    Minimo: " << ed3->getMinimo() << endl;
    cout << "    Maximo: " << ed3->getMaximo() << endl;
    cout << "    Orientacao: " << (ed3->temOrientacaoHorizontal() ? "Horizontal" : "Vertical") << endl << endl;

    // Criando lista e Serie para proximo teste
    list<Serie*>* series2 = new list<Serie*>;
    SerieNormal* s4 = new SerieNormal("Serie_4", "EixoX4", "EixoY4");
    SerieNormal* s5 = new SerieNormal("Serie_5", "EixoX5", "EixoY5");
    s4->adicionar(2, 17);
    s5->adicionar(1.999999,17.00001);
    s5->adicionar(2.000009,17.000005);
    series2->push_back(s4);
    series2->push_back(s5);

    /* Teste de valores maximos e minimos muito proximos */
    EixoDinamico *ed4 = new EixoDinamico("Teste_4", -1, 99, series2, 1);
    cout << "Titulo do eixo: " << ed4->getTitulo() << endl;
    cout << "    Minimo: " << ed4->getMinimo() << endl;
    cout << "    Maximo: " << ed4->getMaximo() << endl;
    cout << "    Orientacao: " << (ed4->temOrientacaoHorizontal() ? "Horizontal" : "Vertical") << endl << endl;
    return 0;
}
