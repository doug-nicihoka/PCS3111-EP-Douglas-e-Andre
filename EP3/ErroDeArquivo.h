#ifndef ERRODEARQUIVO_H
#define ERRODEARQUIVO_H
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
class ErroDeArquivo : public logic_error  {
    public:
        ErroDeArquivo(string mensagem);
      //  virtual ~ErroDeArquivo();
};

#endif // ERRODEARQUIVO_H
