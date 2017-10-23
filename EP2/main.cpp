include <iostream>
#include <string>
#include "Serie.h"
#include "SerieTemporal.h"
#include "Ponto.h"
#include "Eixo.h"
#include "EixoDinamico.h"
#include "InterfaceSerial.h"
#include "Grafico.h"
using std::string;
using std::cout;
using std::endl;

#define COMM "\\\\.\\COM3"

int main() {
  InterfaceSerial* is = new InterfaceSerial(COMM);
  is->inicializar();
  string nomeDaSerie, canalX, canalY ;
  int numX, numY;
  char tipoX, tipoY;

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
  Serie* s = new Serie(nomeDaSerie, canalX, canalY);
  //Gerar o Grafico
  cout << "Gerando o grafico " ;
  cout << "O eixo X é estatico ou dinamico (e/d): ";
  cin >> tipoX;
  if(tipoX == 'e') {
    string tituloEixoX;
    double maximoEixoX, minimoEixoX;
    cout << "Informe o titulo: ";
    cin >> tituloEixoX;
    cout << "Valor minimo: ";
    cin >> minimoEixoX;
    cout << "Valor maximo:";
    cin >> maximoEixoX;
    Eixo *eixoX = new Eixo(tituloEixoX, minimoEixoX, maximoEixoX);
  }
  else {
    double maximoPadraoEixoX, minimoPadraoEixoX;
    cout << "Valor minimo padrao: ";
    cin >> minimoPadraoEixoX;
    cout << "Valor maximo:";
    cin >> maximoPadraoEixoX;
    EixoDinamico *eixoX = new EixoDinamico(minimoPadraoEixoX, maximoPadraoEixoX, s, true);
  }

  cout << "O eixo Y é estatico ou dinamico (e/d): ";
  cin >> tipoY;
  if(tipoY == 'e') {
    string tituloEixoY;
    double maximoEixoY, minimoEixoY;
    cout << "Informe o titulo: ";
    cin >> tituloEixoY;
    cout << "Valor minimo: ";
    cin >> minimoEixoY;
    cout << "Valor maximo:";
    cin >> maximoEixoY;
    Eixo *eixoY = new Eixo(tituloEixoY, minimoEixoY, maximoEixoY);
  }
  else {
    double maximoPadraoEixoY, minimoPadraoEixoY;
    cout << "Valor minimo padrao: ";
    cin >> minimoPadraoEixoY;
    cout << "Valor maximo:";
    cin >> maximoPadraoEixoY;
    EixoDinamico *eixoY = new EixoDinamico(minimoPadraoEixoY, maximoPadraoEixoY, s, false);
  }
  Grafico* g = new Grafico(eixoX, eixoY, s);
  g->desenhar();
  return 0;
}
