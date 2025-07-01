#ifndef HASH_HPP
#define HASH_HPP

#include <bits/stdc++.h>
#include "Gema.hpp"


#define HASH_TABLE_SIZE 1428

unsigned int hashfunctionID (int id)
{
    return id % HASH_TABLE_SIZE;
}

int hashFunctionIntensidade (double intensidade)
{
    double valorNormalizado = (intensidade / 100.0) * 255.0;
    int indiceDiscreto = static_cast<int>(round(valorNormalizado));
    if (indiceDiscreto < 0) indiceDiscreto = 0;
    if (indiceDiscreto > 255) indiceDiscreto = 255;
    return indiceDiscreto % HASH_TABLE_SIZE;
}

Gema *hashtableID[HASH_TABLE_SIZE];

Gema *hashtableIntensidade[HASH_TABLE_SIZE];

void incializaTabelaHash ()
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        hashtableID[i] = nullptr;
        hashtableIntensidade[i] = nullptr;
    }
}

bool inserirNasTabelasHash (Gema *gema)
{
    if (gema == nullptr)
        return false;

    unsigned int idHash = hashfunctionID(gema->id);
    unsigned int intensidadeHash = hashFunctionIntensidade(gema->intensidade);

    gema->proxID = hashtableID[idHash];
    hashtableID[idHash] = gema;


    gema->proxIntensidade = hashtableIntensidade[intensidadeHash];
    hashtableIntensidade[intensidadeHash] = gema;

    return true;
}

Gema *consultaTabelaHashID (int id, int& saltos)
{
    int index = hashfunctionID(id);
    Gema* atual = hashtableID[index];
    while (atual != nullptr) 
    {   
        saltos++;
        if (atual->id == id) return atual;
        atual = atual->proxID;
    }
    return nullptr;
}

Gema *consultaTabelaHashIntensidade (double intensidade, int& saltos)
{
    int index = hashFunctionIntensidade(intensidade);
    Gema * atual = hashtableIntensidade[index];
    while (atual != nullptr)
    {
        saltos++;
        if (atual->intensidade == intensidade) return atual;
        atual = atual->proxIntensidade;
    }
    return nullptr;
}

bool deletarNasTabelasHash(Gema* gema) {
    if (gema == nullptr) return false;

    int indexID = hashfunctionID(gema->id);
    Gema* atualID = hashtableID[indexID];
    Gema* anteriorID = nullptr;

    while (atualID != nullptr) {
        if (atualID == gema) {
            if (anteriorID == nullptr) {
                hashtableID[indexID] = atualID->proxID;
            } else {
                anteriorID->proxID = atualID->proxID;
            }
            break;
        }
        anteriorID = atualID;
        atualID = atualID->proxID;
    }

    int indexInt = hashFunctionIntensidade(gema->intensidade);
    Gema* atualInt = hashtableIntensidade[indexInt];
    Gema* anteriorInt = nullptr;

    while (atualInt != nullptr) {
        if (atualInt == gema) {
            if (anteriorInt == nullptr) {
                hashtableIntensidade[indexInt] = atualInt->proxIntensidade;
            } else {
                anteriorInt->proxIntensidade = atualInt->proxIntensidade;
            }
            break;
        }
        anteriorInt = atualInt;
        atualInt = atualInt->proxIntensidade;
    }

    return true;
}

vector<Gema*> consultarTodasTabelaHashID(int id, int& saltos)
{
    vector<Gema*> resultados;
    int index = hashfunctionID(id);
    Gema* atual = hashtableID[index];

    while (atual != nullptr)
    {
        saltos++;
        if (atual->id == id)
        {
            resultados.push_back(atual);
        }
        atual = atual->proxID;
    }

    return resultados;
}

vector<Gema*> consultarTodasTabelaHashIntensidade(double intensidade, int& saltos)
{
    vector<Gema*> resultados;
    int index = hashFunctionIntensidade(intensidade);
    Gema* atual = hashtableIntensidade[index];

    while (atual != nullptr)
    {
        saltos++;
        if (atual->intensidade == intensidade)
        {
            resultados.push_back(atual);
        }
        atual = atual->proxIntensidade;
    }

    return resultados;
}

#endif 