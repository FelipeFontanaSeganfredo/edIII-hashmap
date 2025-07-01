// main.cpp

#include <bits/stdc++.h>
#include "Gema.hpp"
#include "Parser.hpp"
#include "Print_functions.hpp"
#include "Hash.hpp"
#include "Busca_binaria.hpp"
#include "Raio.hpp"

#define HASH_TABLE_SIZE 1428


using namespace std;
using namespace std::chrono;

int main() {
    incializaTabelaHash();

    vector<Gema> gemas;
    string nomeArquivoDeEntrada = "gemas2.txt";
    gemas = retornaGemas(nomeArquivoDeEntrada);

    // variáveis do menu
    bool invalido = false;
    int escolha = -1;

    Gema *novaGemaConsulta = nullptr;
    vector<Gema*> novoVetorGemasConsulta;

    string cor = "";
    double intensidade = 0;
    int saltos = 0;

    do {
        cout << "\n ***$$$ MENU &&&***\n";
        cout << "1 - Buscar gema por ID - unico\n";
        cout << "2 - Buscar gema por ID - multiplo\n";
        cout << "3 - Buscar gema por cor (busca binaria)\n";
        cout << "4 - Buscar gema por id (busca binaria)\n";
        cout << "5 - Buscar gema por intensidade (busca binaria)\n";
        cout << "6 - Buscar gema por intensidade\n";
        cout << "7 - Aplicar raio\n";
        cout << "8 - Mostrar hashtables\n";
        cout << "0 - Encerrar\n";
        cin >> escolha;

        switch (escolha) {
        case 0:
            invalido = true;
            break;

        case 1: {
            cout << "Insira o ID que deseja buscar: ";
            int id;
            cin >> id;

            auto inicio = high_resolution_clock::now();
            novaGemaConsulta = consultaTabelaHashID(id, saltos);
            auto fim = high_resolution_clock::now();

            printarUmaGema(novaGemaConsulta);
            cout << "\nForam necessários " << saltos << " saltos\n";
            cout << "Tempo: " << duration_cast<nanoseconds>(fim - inicio).count() << "ns\n";
            saltos = 0;
            break;
        }

        case 2: {
            cout << "Insira o ID que deseja buscar: ";
            int id;
            cin >> id;

            auto inicio = high_resolution_clock::now();
            novoVetorGemasConsulta = consultarTodasTabelaHashID(id, saltos);
            auto fim = high_resolution_clock::now();

            printarTodasGemasPonteiro(novoVetorGemasConsulta);
            cout << "\nForam necessários " << saltos << " saltos\n";
            cout << "Tempo: " << duration_cast<nanoseconds>(fim - inicio).count() << "ns\n";
            saltos = 0;
            break;
        }

        case 3: {
            cout << "Insira a cor que deseja buscar (adicione #): ";
            cin.ignore(); getline(cin, cor);
            ordenarGemasCor(&gemas);

            auto inicio = high_resolution_clock::now();
            novaGemaConsulta = buscaBinariaUnitariaCor(&gemas, cor, saltos);
            auto fim = high_resolution_clock::now();

            printarUmaGema(novaGemaConsulta);
            cout << "\nForam necessários " << saltos << " saltos\n";
            cout << "Tempo: " << duration_cast<nanoseconds>(fim - inicio).count() << "ns\n";
            saltos = 0;
            break;
        }

        case 4: {
            cout << "Insira o ID que deseja buscar: ";
            int id;
            cin >> id;
            ordenarGemasID(&gemas);

            auto inicio = high_resolution_clock::now();
            novaGemaConsulta = buscaBinariaID(&gemas, id, saltos);
            auto fim = high_resolution_clock::now();

            printarUmaGema(novaGemaConsulta);
            cout << "\nForam necessários " << saltos << " saltos\n";
            cout << "Tempo: " << duration_cast<nanoseconds>(fim - inicio).count() << "ns\n";
            saltos = 0;
            break;
        }

        case 5: {
            cout << "Insira a cor que deseja saber a intensidade (adicione #): ";
            cin.ignore(); getline(cin, cor);
            intensidade = calcularIntensidade(cor);
            ordenarGemasIntensidade(&gemas);

            auto inicio = high_resolution_clock::now();
            novoVetorGemasConsulta = buscaBinariaIntensidade(&gemas, intensidade, saltos);
            auto fim = high_resolution_clock::now();

            printarTodasGemasPonteiro(novoVetorGemasConsulta);
            cout << "\nForam necessários " << saltos << " saltos\n";
            cout << "Tempo: " << duration_cast<nanoseconds>(fim - inicio).count() << "ns\n";
            saltos = 0;
            break;
        }

        case 6: {
            cout << "Insira a cor que deseja saber a intensidade (adicione #): ";
            cin.ignore(); getline(cin, cor);
            intensidade = calcularIntensidade(cor);

            auto inicio = high_resolution_clock::now();
            novoVetorGemasConsulta = consultarTodasTabelaHashIntensidade(intensidade, saltos);
            auto fim = high_resolution_clock::now();

            printarTodasGemasPonteiro(novoVetorGemasConsulta);
            cout << "\nForam necessários " << saltos << " saltos\n";
            cout << "Tempo: " << duration_cast<nanoseconds>(fim - inicio).count() << "ns\n";
            saltos = 0;
            break;
        }

        case 7:
            aplicarRaio(&gemas);
            break;

        case 8:
            printarHashTableID();
            printarHashTableIntensidade();
            cout << "\nTamanho do vetor de gemas em bytes: " << sizeof(Gema) * gemas.size();
            cout << "\nTamanho das hashtables: " << sizeof(hashtableID) << " " << sizeof(hashtableIntensidade) << "\n";
            break;

        default:
            cout << "Opção inválida!\n";
            break;
        }

    } while (!invalido);

    return 0;
}
