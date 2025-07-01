#ifndef PARSER_HPP
#define PARSER_HPP

#include <bits/stdc++.h>
#include "Gema.hpp"
#include "Hash.hpp"

/* o presente arquivo tem como objetivo realizar todas as etapas 
   de leitura e parseamento do arquivo de entrada, retornando um vector<Gema>
*/

string retornaId(string linha) {
    size_t idPos = linha.find("\"id\":");
    if (idPos == string::npos) return "";

    size_t start = linha.find(":", idPos) + 1;
    size_t end = linha.find(",", start);

    return linha.substr(start, end - start);
}

string retornaCor(string linha) {
    size_t corPos = linha.find("\"cor\":\"");
    if (corPos == string::npos) return "";

    size_t start = linha.find("\"", corPos + 6) + 1;
    size_t end = linha.find("\"", start);

    return linha.substr(start, end - start);
}


vector<Gema> retornaGemas (string nomeArquivoEntrada)
{
    vector<Gema> resultados;
    ifstream arquivo(nomeArquivoEntrada);

    if (!arquivo.is_open())
    {
        cout << "\nNão foi possível abrir o arquivo\n";
        return resultados;
    }

    string linha;

    while (getline(arquivo, linha))
    {
        Gema* novaGema = new Gema;
        novaGema->id = stoi(retornaId(linha));
        novaGema->corHex = retornaCor(linha);
        novaGema->intensidade = calcularIntensidade(novaGema->corHex);
        novaGema->proxID = nullptr;
        novaGema->proxIntensidade = nullptr;
        inserirNasTabelasHash(novaGema);

        resultados.push_back(*novaGema); 
    }

    return resultados;
}


#endif