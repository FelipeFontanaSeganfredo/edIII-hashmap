// Gema.h

#ifndef GEMA_HPP
#define GEMA_HPP

#include<bits/stdc++.h>

/*
O presente arquivo é destinado à criação da struct de gema, bem como
funções de conversão de luminosidade
*/

using namespace std;

struct Gema {
    int id;
    string corHex;
    double intensidade;
    Gema *proxID;
    Gema *proxIntensidade;
};

int hexCharParaInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    else if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

unsigned int retornaHexUInt (string hex)
{
    unsigned int resultado = 0;
    for (int i = 1; i < hex.size(); i++)
    {
        resultado = resultado * 16 + hexCharParaInt(hex[i]);
    }
    return resultado;
}

vector<int> hexParaRGB (unsigned int valorHex)
{
    vector<int> RGB;
    int r = (valorHex >> 16) & 0xFF;
    int g = (valorHex >> 8) & 0xFF;
    int b = valorHex & 0xFF;

    RGB.push_back(r);
    RGB.push_back(g);
    RGB.push_back(b);

    return RGB;
}

double retornaLuminosidadeHSV (vector<int> RGB)
{
    int r = RGB[0];
    int g = RGB[1];
    int b = RGB[2];

    double valorMax = max({r, g, b});

    return (valorMax / 255.0) * 100;
}

double calcularIntensidade (string hex)
{
    unsigned int valUInt = retornaHexUInt(hex);
    vector<int> rgb = hexParaRGB(valUInt);
    double intensidade = retornaLuminosidadeHSV(rgb);
    return intensidade;
}

bool ordenarGemasCor (vector<Gema> *vetorDeGemas)
{
    if (vetorDeGemas == nullptr)
    {
        return false;
    }
    sort(vetorDeGemas->begin(), vetorDeGemas->end(), [](const Gema& a, const Gema& b) 
    {
        return a.corHex < b.corHex;
    });
    return true;
}

bool ordenarGemasID (vector<Gema> *vetorDeGemas)
{
    if (vetorDeGemas == nullptr)
    {
        return false;
    }
    sort(vetorDeGemas->begin(), vetorDeGemas->end(), [](const Gema& a, const Gema& b)
    {
        return a.id < b.id;
    });
    return true;
}

bool ordenarGemasIntensidade (vector<Gema> *vetorDeGemas)
{
    if (vetorDeGemas == nullptr)
    {
        return false;
    }
    sort(vetorDeGemas->begin(), vetorDeGemas->end(), [](const Gema& a, const Gema& b)
    {
        return a.intensidade < b.intensidade;
    });
    return true;
}

string gerarCorHexAleatoria() {
    stringstream ss;
    ss << "#";
    for (int i = 0; i < 6; ++i) {
        int val = std::rand() % 16;
        if (val < 10) {
            ss << val;
        } else {
            ss << (char)('A' + (val - 10));
        }
    }
    return ss.str();
}

#endif