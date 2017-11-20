#include "ErroDeArquivo.h"

ErroDeArquivo::ErroDeArquivo(std::string mensagem) : std::logic_error (mensagem) {}

