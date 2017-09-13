#include <iostream>
#include <string>
#include "Serie.h"
#include "Ponto.h"
#include "InterfaceSerial.h"

#define COMM "\\\\.\\COM3"

using namespace std;

int main() {
  InterfaceSerial* is = new InterfaceSerial();
  is->inicializar(COMM);
  string nomeDaSerie, canalX, canalY;
  int numX, numY;

  // Obtem o nome da Serie e os canais escolhidos
  cout << "Informe o nome da serie: ";
  cin >> nomeDaSerie;

  cout << "Escolha o canal X: " << endl;
  for(int i = 1; i <= is->getQuantidadeDeCanais(); i++)
    cout << i << ") " << *(is->getNomeDosCanais() + (i - 1)) << endl;
  cin >> numX;
  canalX = *(is->getNomeDosCanais() + (numX - 1));

  cout << "Escolha o canal Y:" << endl;
  for(int i = 1; i <= is->getQuantidadeDeCanais(); i++)
    cout << i << ") " << *(is->getNomeDosCanais() + (i - 1)) << endl;
  cin >> numY;
  canalY = *(is->getNomeDosCanais() + (numY - 1));

  // Obtem o numero de Pontos a adicionar
  int quantidade;
  cout << "Obter quantos pontos? ";
  cin >> quantidade;

  // Cria a Serie
  Serie *serie = new Serie;

  cout << "Obtendo os pontos" << endl;
  for (int i = 0; i < quantidade; i++) {
    is->atualizar();
    serie->adicionar(is->getValor(canalX), is->getValor(canalY));
  }
  serie->setNome(nomeDaSerie);

  cout << "Imprimindo os pontos obtidos" << endl;
  serie->imprimir();

  cout << "Limite Superior: ";
  serie->getLimiteSuperior()->imprimir();

  cout << "Limite Inferior: ";
  serie->getLimiteInferior()->imprimir();
  return 0;
}
