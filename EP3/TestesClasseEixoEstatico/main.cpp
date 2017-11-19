#include <iostream>
#include <stdexcept>
#include "Eixo.h"
#include "EixoEstatico.h"

using namespace std;

int main()
{
    EixoEstatico *ee = new EixoEstatico("Eixo x", -158.9534, 425.682, 1);
    cout << "Titulo do eixo: " << ee->getTitulo() << endl;
    cout << "Valor maximo do eixo: " << ee->getMaximo() << endl;
    cout << "Valor minimo do eixo: " << ee->getMinimo() << endl;
    cout << "Eh horizontal? " << (ee->temOrientacaoHorizontal() ? "Sim" : "Não") << endl;

    try {
        ee = new EixoEstatico("Teste", -18, -19, 0);
        cout << "Valor maximo do eixo: " << ee->getMaximo() << endl;
        cout << "Valor minimo do eixo: " << ee->getMinimo() << endl;
    }
    catch (runtime_error *e) {
        cout << e->what() << endl;
        delete e;
    }
    delete ee;
    return 0;
}
