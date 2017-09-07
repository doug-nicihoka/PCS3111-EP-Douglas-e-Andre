#include "InterfaceSerial.h"

void InterfaceSerial::inicializar(string porta) {
    nomes[0] = "T1";
    nomes[1] = "T2";
}

double InterfaceSerial::getValor(string canal) {
    int valoresT1[] = {10, 20, 30, 40};
    int valoresT2[] = {10, 15, 20, 25};
    if (canal == "T1") return valoresT1[numeroDeChamadas];
    return valoresT2[numeroDeChamadas];
}

bool InterfaceSerial::atualizar() {
    numeroDeChamadas++;
    return true;
}

string* InterfaceSerial::getNomeDosCanais() {
    return nomes;
}

int InterfaceSerial::getQuantidadeDeCanais() {
    return 2;
}
