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
#include "PersistenciaDeSerie.h"

using namespace std;

#define COMM "\\\\.\\COM3"

int main() {
    /* Cria e inicializa instancia de InterfaceSerial */
    InterfaceSerial* is = new InterfaceSerial(COMM);
    try {
        is->inicializar();
    }
    catch (runtime_error* e) {
        cout << e->what() << endl; delete e; return 0;
    }



    /* Obtém o nome do arquivo com os dados da Series */
    string dados;
    cout << "Informe o nome do arquivo de dados: ";
    cin >> dados;



    /* Obtém o nome da Serie e os canais escolhidos */
	list<Serie*>* series = new list<Serie*>();
    char continuar;

    // Loop válido enquanto o usuário desejar adicionar outra serie
    do {
        string nome;
        cout << "Informe o nome da serie: ";
        cin >> nome;

        cout << "Escolha o canal X:" << endl;
        cout << "0) Tempo" << endl;
        for(int i = 1; i <= is->getQuantidadeDeCanais(); i++)
            cout << i << ") " << *(is->getNomeDosCanais() + (i - 1)) << endl;
        int numX;
        cin >> numX;
        string canalX;
        if (numX > 0)
            canalX = *(is->getNomeDosCanais() + (numX - 1));
        else if (numX == 0)
			canalX = "Tempo";

        cout << "Escolha o canal Y:" << endl;
        for(int i = 1; i <= is->getQuantidadeDeCanais(); i++)
            cout << i << ") " << *(is->getNomeDosCanais() + (i - 1)) << endl;
        int numY;
        cin >> numY;
        string canalY;
		canalY = *(is->getNomeDosCanais() + (numY - 1));

		if (numX > 0)
			series->push_back(new SerieNormal(nome, canalX, canalY));
		else if (numX == 0)
			series->push_back(new SerieTemporal(nome, canalY));

        cout << "Adicionar uma outra serie (s/n): ";
        cin >> continuar;
    }
    while (continuar == 's');



    /* Adiciona os pontos às Series */
    try {
        // Obtem o numero de Pontos a adicionar
        int quantidade;
        cout << "Obter quantos pontos? ";
        cin >> quantidade;

		cout << "Obtendo os pontos" << endl;

        for (list<Serie*>::iterator it = series->begin(); it != series->end(); ++it) {
            if ((*it)->getNomeDoCanalX() == "Tempo" ) {
                if (SerieTemporal* st = dynamic_cast<SerieTemporal*>(*it)) {
                    for (int i = 0; i < quantidade; ++i) {
                        is->atualizar();
                        st->adicionar(is->getValor(st->getNomeDoCanalY()));
                    }
                }
            }
            else {
                if (SerieNormal* sn = dynamic_cast<SerieNormal*>(*it)) {
                    for (int i = 0; i < quantidade; ++i) {
                        is->atualizar();
                        sn->adicionar(is->getValor(sn->getNomeDoCanalX()), is->getValor(sn->getNomeDoCanalY()));
					}
                }
            }
		}
    }
    // Captura exceções dos métodos atualizar e getValor da InterfaceSerial
    catch (logic_error* e) {
        cout << e->what() << endl; delete e; return 0;
    }
    catch (runtime_error* e) {
        cout << e->what() << endl; delete e; return 0;
    }



    /* Carrega arquivo com Series */
    PersistenciaDeSerie* ps;
    vector<string> seriesPersistidas;
    cout << "Deseja carregar alguma serie? (s/n) ";
    cin >> continuar;

    try {
        ps = new PersistenciaDeSerie(dados);
    }
    catch (ErroDeArquivo* e) {
        cout << e->what() << endl; delete e; return 0;
    }

    if (continuar == 's') {
        seriesPersistidas = *(ps->getNomes());
        if (seriesPersistidas.empty())
            cout << "Sem series salvas." << endl;
        else {
            do {
                int i = 0;
                for (vector<string>::iterator it = seriesPersistidas.begin(); it != seriesPersistidas.end(); ++it)
                    cout << ++i << ") " << *it << endl;
                cout << "Escolha a serie para carregar: ";
                cin >> i;

                series->push_back(ps->obter(seriesPersistidas[i-1]));

                cout << "Deseja carregar outra serie? (s/n) ";
                cin >> continuar;
            }
            while (continuar == 's');
        }
    }



    /* Obtém os eixos */
    Eixo* eixoX;
    Eixo* eixoY;

    try {
        string titulo;
        double maximo, minimo;
        char tipo;

        // Define o eixo X
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
        // Define o eixo Y */
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
    }
    // Captura exceções durante a criação dos eixos
    catch (runtime_error* e) {
        cout << e->what() << endl; delete e; return 0;
    }
    catch (logic_error* e) {
        cout << e->what() << endl; delete e; return 0;
    }



    /* Desenha o grafico */
    vector<Serie*>* vectorSeries = new vector<Serie*>;
    vectorSeries->reserve(series->size());
    copy(begin(*series), std::end(*series), back_inserter(*vectorSeries));

    try {
        Grafico* g;
        g = new Grafico(eixoX, eixoY, vectorSeries);
        g->desenhar();
        delete g;
    }
    // Captura exceções durante a criação do grafico
    catch (logic_error* e) {
        cout << e->what() << endl; delete e; return 0;
    }


    /* Salva Series */
    cout << "Deseja salvar alguma serie? (s/n) ";
    cin >> continuar;
    if (continuar == 's') {
        do {
            int i = 0;
            for (vector<Serie*>::iterator it = vectorSeries->begin(); it != vectorSeries->end(); ++it)
                cout << ++i << ") " << (*it)->getNome() << endl;
            cout << "Escolha a serie para salvar: ";
            cin >> i;

            string nome;
            cout << "Salvar a serie com qual nome: ";
            cin >> nome;

            try {
                ps->inserir(nome, vectorSeries->at(i-1));
            }
            // Captura exceção do método inserir
            catch (ErroDeArquivo* e) {
                cout << e->what() << endl; delete e; return 0;
            }

            cout << "Deseja salvar outra serie? (s/n) ";
            cin >> continuar;
        }
        while (continuar == 's');
    }

    // Remove instancia de PersistenciaDeSerie
    delete ps;

    // Remove os eixos criados
    delete eixoX;
    delete eixoY;

    // Remove a list com as series
    for (list<Serie*>::iterator it = series->begin(); it != series->end(); ++it)
        delete *it;
    series->clear();
    delete series;

    // Remove o vector com as series
    vectorSeries->clear();
    delete vectorSeries;

    // Remove instancia de InterfaceSerial
    delete is;

    return 0;
}
