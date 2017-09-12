#include <iostream>
#include "Ponto.h"

using namespace std;

int main()
{
    Ponto* p = new Ponto;
    Ponto* q = new Ponto;

    /* Testando setters e getters */
    p->setX(-12345.12341);
    p->setY(12345.12339);
    cout << "Ponto p com getters: (" << p->getX() << ", " << p->getY() << ")" << endl << endl;

    q->setX(-12345.12340);
    q->setY(12345.12340);
    cout << "Ponto q com getters: (" << q->getX() << ", " << q->getY() << ")" << endl << endl;


    /* Testando metodo imprimir */
    cout << "Ponto p com imprimir: "; p->imprimir();
    cout << endl;
    cout << "Ponto q com imprimir: "; q-> imprimir();
    cout << endl;


    /* Testando metodo eIgual */
    if (p->eIgual(q) && q->eIgual(p)) cout << "p e q iguais" << endl << endl;
    else cout << "p e q diferentes" << endl << endl;

    return 0;
}
