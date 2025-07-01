#ifndef RAIO_HPP
#define RAIO_HPP

#include<bits/stdc++.h>
#include "Gema.hpp"
#include "Hash.hpp"
#include "Print_functions.hpp"

using namespace std;


bool aplicarRaio(vector<Gema> *gemas)
{
    if (gemas == nullptr)
    {
        return false;
    }
    srand(time(nullptr));
    int numeroAleatorio = rand() % gemas->size() + 1;

    
    int indiceAleatorio = std::rand() % gemas->size();
    Gema *gemaAfetada = &(*gemas)[indiceAleatorio];

    int id = gemaAfetada->id; 

    deletarNasTabelasHash(gemaAfetada);

    gemaAfetada->id = id;
    string corHex = gerarCorHexAleatoria();
    gemaAfetada->corHex = corHex;
    gemaAfetada->intensidade = calcularIntensidade(corHex);

    inserirNasTabelasHash(gemaAfetada);

    printarRaio(*gemaAfetada);

    return true;
}

#endif