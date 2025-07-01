#ifndef PRINT_FUNCTIONS_HPP
#define PRINT_FUNCTIONS_HPP

#include<bits/stdc++.h>
#include "Gema.hpp"
#include "Hash.hpp"

#define HASH_TABLE_SIZE 101

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
        cout << "Hash ID: " << hashfunctionID(gema.id) << "\n";
        cout << "Hash Intensidade: " << hashFunctionIntensidade(gema.intensidade) << "\n";
    }
    
}

void printarHashTableID ()
{
    cout << "#### INÍCIO HASH POR ID ####\n";
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        cout << "[" << i << "]: ";
        if (hashtableID[i] == nullptr)
        {
            cout << "(vazio)";
        }
        else
        {
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
        cout << "[" << i << "]: ";
        if (hashtableIntensidade[i] == nullptr)
        {
            cout << "(vazio)";
        }
        else
        {
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


#endif