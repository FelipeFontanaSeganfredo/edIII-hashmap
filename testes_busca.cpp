#include <bits/stdc++.h>
#include <fstream>
#include "Gema.hpp"
#include "Parser.hpp"
#include "Hash.hpp"
#include "Busca_binaria.hpp"

using namespace std;
using namespace std::chrono;

void testarBuscas(const vector<Gema>& gemas, ofstream& out) {
    vector<Gema> gemasCopia = gemas; // para ordenações sem afetar original

    ordenarGemasID(&gemasCopia);
    ordenarGemasIntensidade(&gemasCopia);

    for (int i = 0; i < 100 && i < gemas.size(); i++) {
        const Gema& g = gemas[i];
        int saltosBin = 0, saltosHash = 0;

        // --- BUSCA POR ID ---
        auto inicioHashID = high_resolution_clock::now();
        consultaTabelaHashID(g.id, saltosHash);
        auto fimHashID = high_resolution_clock::now();

        auto inicioBinID = high_resolution_clock::now();
        buscaBinariaID(&gemasCopia, g.id, saltosBin);
        auto fimBinID = high_resolution_clock::now();

        // saída: tipo,valor,saltos,tempo_ns
        out << "ID," << g.id << ",Hash," << saltosHash << "," << duration_cast<nanoseconds>(fimHashID - inicioHashID).count() << "\n";
        out << "ID," << g.id << ",Binaria," << saltosBin << "," << duration_cast<nanoseconds>(fimBinID - inicioBinID).count() << "\n";

        // --- BUSCA POR INTENSIDADE ---
        double intensidade = g.intensidade;
        saltosBin = 0;
        saltosHash = 0;

        auto inicioHashInt = high_resolution_clock::now();
        consultarTodasTabelaHashIntensidade(intensidade, saltosHash);
        auto fimHashInt = high_resolution_clock::now();

        auto inicioBinInt = high_resolution_clock::now();
        buscaBinariaIntensidade(&gemasCopia, intensidade, saltosBin);
        auto fimBinInt = high_resolution_clock::now();

        out << "INT," << intensidade << ",Hash," << saltosHash << "," << duration_cast<nanoseconds>(fimHashInt - inicioHashInt).count() << "\n";
        out << "INT," << intensidade << ",Binaria," << saltosBin << "," << duration_cast<nanoseconds>(fimBinInt - inicioBinInt).count() << "\n";
    }
}

int main() {
    incializaTabelaHash();
    string arquivoEntrada = "gemas2.txt";

    vector<Gema> gemas = retornaGemas(arquivoEntrada);

    for (auto& gema : gemas) {
        inserirNasTabelasHash(&gema);
    }

    ofstream out("resultados_busca.csv");
    out << "Tipo,Valor,Metodo,Saltos,Tempo_ns\n"; // cabeçalho
    testarBuscas(gemas, out);
    out.close();

    cout << "Testes concluídos. Resultados salvos em 'resultados_busca.csv'\n";
    return 0;
}
