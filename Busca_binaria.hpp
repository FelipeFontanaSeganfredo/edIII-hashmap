#ifndef BUSCAS_BINARIAS_HPP
#define BUSCAS_BINARIAS_HPP

#include <bits/stdc++.h>
#include "Gema.hpp"
#include "Print_functions.hpp"

using namespace std;

Gema* buscaBinariaUnitariaCor(vector<Gema>* vetorDeGemas, string corHex, int& saltos) {
    if (vetorDeGemas == nullptr || vetorDeGemas->empty()) return nullptr;

    int esquerda = 0;
    int direita = vetorDeGemas->size() - 1;

    while (esquerda <= direita) {
        saltos++;
        int meio = esquerda + (direita - esquerda) / 2;
        if ((*vetorDeGemas)[meio].corHex == corHex) {
            return &(*vetorDeGemas)[meio];
        } else if ((*vetorDeGemas)[meio].corHex < corHex) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return nullptr;
}

vector<Gema*> buscaBinariaMultiplaCor(vector<Gema>* vetorDeGemas, string corHex, int& saltos) {
    vector<Gema*> encontrados;
    if (vetorDeGemas == nullptr || vetorDeGemas->empty()) return encontrados;

    int esquerda = 0;
    int direita = vetorDeGemas->size() - 1;
    int inicio = -1, fim = -1;

    while (esquerda <= direita) {
        saltos++;
        int meio = esquerda + (direita - esquerda) / 2;
        if ((*vetorDeGemas)[meio].corHex == corHex) {
            inicio = meio;
            direita = meio - 1;
        } else if ((*vetorDeGemas)[meio].corHex < corHex) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    esquerda = 0;
    direita = vetorDeGemas->size() - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if ((*vetorDeGemas)[meio].corHex == corHex) {
            fim = meio;
            esquerda = meio + 1;
        } else if ((*vetorDeGemas)[meio].corHex < corHex) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    if (inicio != -1 && fim != -1) {
        for (int i = inicio; i <= fim; ++i) {
            encontrados.push_back(&(*vetorDeGemas)[i]);
        }
    }

    return encontrados;
}

Gema* buscaBinariaID(vector<Gema>* vetorDeGemas, int id, int& saltos) {
    if (vetorDeGemas == nullptr || vetorDeGemas->empty()) return nullptr;

    int esquerda = 0;
    int direita = vetorDeGemas->size() - 1;

    while (esquerda <= direita) {
        saltos++;
        int meio = esquerda + (direita - esquerda) / 2;
        if ((*vetorDeGemas)[meio].id == id) {
            return &(*vetorDeGemas)[meio];
        } else if ((*vetorDeGemas)[meio].id < id) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return nullptr;
}

vector<Gema*> buscaBinariaIntensidade(vector<Gema>* vetorDeGemas, double intensidade, int& saltos) {
    vector<Gema*> encontrados;
    if (vetorDeGemas == nullptr || vetorDeGemas->empty()) return encontrados;

    int esquerda = 0;
    int direita = vetorDeGemas->size() - 1;
    int inicio = -1, fim = -1;

    while (esquerda <= direita) {
        saltos++;
        int meio = esquerda + (direita - esquerda) / 2;
        if (abs((*vetorDeGemas)[meio].intensidade - intensidade) < 1e-6) {
            inicio = meio;
            direita = meio - 1;
        } else if ((*vetorDeGemas)[meio].intensidade < intensidade) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    esquerda = 0;
    direita = vetorDeGemas->size() - 1;
    while (esquerda <= direita) {
        saltos++;
        int meio = esquerda + (direita - esquerda) / 2;
        if (abs((*vetorDeGemas)[meio].intensidade - intensidade) < 1e-6) {
            fim = meio;
            esquerda = meio + 1;
        } else if ((*vetorDeGemas)[meio].intensidade < intensidade) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    if (inicio != -1 && fim != -1) {
        for (int i = inicio; i <= fim; ++i) {
            encontrados.push_back(&(*vetorDeGemas)[i]);
        }
    }

    return encontrados;
}

#endif
