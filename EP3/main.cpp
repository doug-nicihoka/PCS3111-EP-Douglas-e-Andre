#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <list>

#include "Ponto.h"
#include "Serie.h"
#include "SerieNormal.h"
#include "SerieTemporal.h"
#include "Eixo.h"
#include "EixoEstatico.h"
#include "EixoDinamico.h"
#include "InterfaceSerial.h"
#include "Tela.h"
#include "Grafico.h"
#include "ErroDeArquivo.h"

using namespace std;

#define COMM "\\\\.\\COM3"

int main() {
    /* Inicializa e captura exceção em caso de falha */
    InterfaceSerial* is = new InterfaceSerial(COMM);
    try {
        is->inicializar();
    }
    catch (runtime_error *e) {
        cout << e->what() << endl;
        delete e;
        return 0;
    }



    /* Obtém o nome do arquivo com os dados da Series */
    string dados;
    cout << "Informe o nome do arquivo de dados: ";
    cin >> dados;



    /* Obtém o nome da Serie e os canais escolhidos */
    vector<string> nomesSeries, canaisX, canaisY;
    string nome;
    vector<int> numX, numY;
    int numero;
    char continuar = 's';
    // Loop válido enquanto o usuário desejar adicionar outra serie
    do {
        cout << "Informe o nome da serie: ";
        cin >> nome;
        nomesSeries.push_back(nome);

        cout << "Escolha o canal X:" << endl;
        cout << "0) Tempo" << endl;
        for(int i = 1; i <= is->getQuantidadeDeCanais(); i++)
            cout << i << ") " << *(is->getNomeDosCanais() + (i - 1)) << endl;
        cin >> numero;
        numX.push_back(numero);
        if (numero > 0)
            canaisX.push_back(*(is->getNomeDosCanais() + (numero - 1)));
        else if (numero == 0)
            canaisX.push_back("Tempo");

        cout << "Escolha o canal Y:" << endl;
        for(int i = 1; i <= is->getQuantidadeDeCanais(); i++)
            cout << i << ") " << *(is->getNomeDosCanais() + (i - 1)) << endl;
        cin >> numero;
        numY.push_back(numero);
        canaisY.push_back(*(is->getNomeDosCanais() + (numero - 1)));

        cout << "Adicionar uma outra serie (s/n): ";
        cin >> continuar;
    }
    while (continuar == 's');



    /* Obtem o numero de Pontos a adicionar */
    int quantidade;
    cout << "Obter quantos pontos? ";
    cin >> quantidade;



    /* Obtem os Pontos */
    cout << "Obtendo os pontos" << endl;
    list<Serie*>* series = new list<Serie*>();
    list<Serie*>::iterator itSerie;
    int contador = 0;

    try {
        // Loop com iterações = num de Series adicionadas
        for (vector<int>::iterator itX = numX.begin(); itX != numX.end(); ++itX) {
            if ((*itX) == 0) {  // Se Serie é uma SerieTemporal
                series->push_back(new SerieTemporal(nomesSeries[contador], canaisY[contador]));

                if (contador == 0) itSerie = series->begin();
                else ++itSerie;

                SerieTemporal* st = dynamic_cast<SerieTemporal*>(*itSerie);

                if (st) {
                    for (int i = 0; i < quantidade; ++i) {
                            is->atualizar();
                            st->adicionar(is->getValor(canaisY[contador]));
                    }
                }
            }
            else {              // Se Serie é uma SerieNormal
                series->push_back(new SerieNormal(nomesSeries[contador], canaisX[contador], canaisY[contador]));

                if (contador == 0) itSerie = series->begin();
                else ++itSerie;

                SerieNormal* sn = dynamic_cast<SerieNormal*>(*itSerie);

                if (sn) {
                    for (int i = 0; i < quantidade; ++i) {
                        is->atualizar();
                        sn->adicionar(is->getValor(canaisX[contador]), is->getValor(canaisY[contador]));
                    }
                }
            }
            ++contador;
        }
    }
    // Captura exceções dos métodos atualizar e getValor da InterfaceSerial
    catch (logic_error *e) {
        cout << e->what() << endl;
        delete e;
        return 0;
    }
    catch (runtime_error *e) {
        cout << e->what() << endl;
        delete e;
        return 0;
    }



    /* Carrega arquivo com Series */
    char carregarSerie = 'a';
    cout << "Deseja carregar alguma serie? (s/n) ";
    cin >> carregarSerie;
    if (carregarSerie == 's') {
        ifstream entrada;
        entrada.open(dados, ios::ate);
        if (entrada.tellg() == 0)
            cout << "Sem series salvas." << endl;
        else {

        }
    }



    /* Define o eixo X */
    string titulo;
    double maximo, minimo;
    char tipo;
    Eixo* eixoX;
    cout << "O eixo X e' estatico ou dinamico (e/d): ";
    cin >> tipo;

    if(tipo == 'e') {
        cout << "Informe o titulo: ";
        cin >> titulo;
        cout << "Valor minimo: ";
        cin >> minimo;
        cout << "Valor maximo: ";
        cin >> maximo;
        eixoX = new EixoEstatico(titulo, minimo, maximo, true);
    }
    else if (tipo == 'd') {
        cout << "Informe o titulo: ";
        cin >> titulo;
        cout << "Valor minimo padrao: ";
        cin >> minimo;
        cout << "Valor maximo padrao: ";
        cin >> maximo;
        eixoX = new EixoDinamico(titulo, minimo, maximo, series, true);
    }



    /* Define o eixo Y */
    Eixo* eixoY;
    cout << "O eixo Y e' estatico ou dinamico (e/d): ";
    cin >> tipo;

    if(tipo == 'e') {
        cout << "Informe o titulo: ";
        cin >> titulo;
        cout << "Valor minimo: ";
        cin >> minimo;
        cout << "Valor maximo: ";
        cin >> maximo;
        eixoY = new EixoEstatico(titulo, minimo, maximo, false);
    }
    else if (tipo == 'd') {
        cout << "Informe o titulo: ";
        cin >> titulo;
        cout << "Valor minimo padrao: ";
        cin >> minimo;
        cout << "Valor maximo padrao: ";
        cin >> maximo;
        eixoY = new EixoDinamico(titulo, minimo, maximo, series, false);
    }



    /* Desenha o grafico */
    vector<Serie*>* vectorSeries = new vector<Serie*>;
    vectorSeries->reserve(series->size());
    copy(begin(*series), std::end(*series), back_inserter(*vectorSeries));

    Grafico* g;
    g = new Grafico(eixoX, eixoY, vectorSeries);
    g->desenhar();



    /* Salva Series */
    cout << "Deseja salvar alguma serie? (s/n) ";
    cin >> continuar;
    if (continuar == 's') {

    }

    return 0;
}
