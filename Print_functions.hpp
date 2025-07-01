#ifndef PRINT_FUNCTIONS_HPP
#define PRINT_FUNCTIONS_HPP

#include<bits/stdc++.h>
#include "Gema.hpp"
#include "Hash.hpp"

#define HASH_TABLE_SIZE 1428

/*
O presente arquivo é destinado à criação das funções de print 
do programa
*/

void printarTodasGemas (vector<Gema>& gemas)
{
    for (int i = 0; i < gemas.size(); i++)
    {
        Gema gema = gemas[i];
        cout << "--- GEMA ----\n";
        cout << "id: " << gema.id << "\n";
        cout << "corHex: " << gema.corHex << "\n";
        cout << "intensidade: " << gema.intensidade << "\n";
    }
    
}

void printarTodasGemasPonteiro (vector<Gema*>& gemas)
{
    cout << "Todas as gemas da consulta:\n";
    for (int i = 0; i < gemas.size(); i++)
    {
        Gema* gema = gemas[i];
        cout << "--- GEMA ----\n";
        cout << "id: " << gema->id << "\n";
        cout << "corHex: " << gema->corHex << "\n";
        cout << "intensidade: " << gema->intensidade << "\n";
    }
}


void printarUmaGema (Gema *gema)
{
    cout << "--- GEMA ----\n";
    cout << "id: " << gema->id << "\n";
    cout << "corHex: " << gema->corHex << "\n";
    cout << "intensidade: " << gema->intensidade << "\n";
}

void printarHashTableID ()
{
    cout << "#### INÍCIO HASH POR ID ####\n";
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if (hashtableID[i] == nullptr)
        {
            continue;
        }
        else
        {
            if (hashtableID[i] != nullptr)
            {
                cout << "[" << i << "]" << ": ";
            }
            Gema* atual = hashtableID[i];
            while (atual != nullptr)
            {
                cout << atual->id;
                atual = atual->proxID;
                if (atual != nullptr) cout << " -> ";
            }
        }
        cout << "\n";
    }
    cout << "#### FIM ####\n";
}


void printarHashTableIntensidade ()
{
    cout << "#### INÍCIO HASH POR INTENSIDADE ####\n";
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if (hashtableIntensidade[i] == nullptr)
        {
            continue;
        }
        else
        {
            if (hashtableIntensidade[i] != nullptr)
            {
                cout << "[" << i << "]" << ": ";
            }
            Gema* atual = hashtableIntensidade[i];
            while (atual != nullptr)
            {
                cout << fixed << setprecision(4) << atual->intensidade;
                atual = atual->proxIntensidade;
                if (atual != nullptr) cout << " -> ";
            }
        }
        cout << "\n";
    }
    cout << "#### FIM ####\n";
}

void printarRaio (Gema gema)
{
    cout << "****** RAIO APLICADO *******\n";
    cout << "ID: " << gema.id << "\n";
    cout << "Novas informações: \n";
    cout << "Cor Hex: " << gema.corHex << "\n";
    cout << "Intensidade: " << gema.intensidade << "\n";
}


#endif