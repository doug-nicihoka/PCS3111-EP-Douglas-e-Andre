#ifndef PERSISTENCIADESERIE_H
#define PERSISTENCIADESERIE_H

#include <vector>
#include <string>
#include "Serie.h"

class PersistenciaDeSerie {
    private:
        std::string arquivo;
        std::vector<std::string>* nomesSeries;
    public:
        /**
        * Cria um objeto que persiste (insere e lê) no arquivo informado.
        * @throw ErroDeArquivo caso o arquivo não siga o formato.
        */
        PersistenciaDeSerie(std::string arquivo);
        virtual ~PersistenciaDeSerie();

        /**
        * Obtém a Serie com o nome. Caso não haja uma Serie com esse nome,
        * deve-se retornar NULL.
        */
        Serie* obter(std::string nome);

        /**
        * Obtém um vector com os nomes das Series persistidas. Os nomes devem estar
        * na mesma ordem que no arquivo texto (ou seja, a primeira Serie no arquivo
        * deve ficar na posição 0 do vector, a segunda na posição 1, etc.).
        */
        std::vector<std::string>* getNomes();

        /**
        * Persiste a Serie s usando um nome.
        * @throw ErroDeArquivo caso não seja possivel escrever no arquivo ou
        * caso já exista uma Serie com o mesmo nome.
        */
        void inserir(std::string nome, Serie* s);
};

#endif // PERSISTENCIADESERIE_H
