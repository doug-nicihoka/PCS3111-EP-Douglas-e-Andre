#ifndef ERRODEARQUIVO_H
#define ERRODEARQUIVO_H

#include <stdexcept>

class ErroDeArquivo : public std::logic_error {
    public:
        ErroDeArquivo(std::string mensagem);
};

#endif // ERRODEARQUIVO_H
