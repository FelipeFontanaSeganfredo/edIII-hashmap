// main.cpp

#include <bits/stdc++.h>
#include "Gema.hpp" 
#include "Parser.hpp"
#include "Print_functions.hpp"
#include "Hash.hpp"

#define HASH_TABLE_SIZE 101

int main() {

    incializaTabelaHash();

    vector<Gema> gemas;

    string nomeArquivoDeEntrada = "gemas.txt";

    gemas = retornaGemas(nomeArquivoDeEntrada);

    // printarTodasGemas(gemas);

    printarHashTableID();

    printarHashTableIntensidade();

    Gema *gema = consultaTabelaHashID(12);

    /*
    if (gema)
    {
        cout << "Gema com id " << gema->id << " está na tabela hash de id\n"; 
    }
    else
        cout << "Não achou!";

    deletarNasTabelasHash(gema);

    gema = consultaTabelaHashID(12);

    if (gema)
    {
        cout << "Gema com id " << gema->id << " está na tabela hash de id\n"; 
    }
    else
        cout << "Não achou!\n";
    */

    return 0;
}



