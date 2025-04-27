#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dividir_instrucoes (const string& linha) {
    vector<string> partes;
    stringstream ss(linha);
    string palavra;

    while (ss >> palavra) {
        // Remove vírgula se existir no final da palavra
        if (!palavra.empty() && palavra.back() == ',') {
            palavra.pop_back(); // Remove a vírgula
        }
        partes.push_back(palavra);
    }

    return partes;
}

vector<vector<string>> lerInstrucoes (const string& nome_do_arquivo) {
    ifstream arquivo(nome_do_arquivo);
    vector<vector<string>> instrucoes;
    vector<string> partes;
    string linha;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o aquivo: " << nome_do_arquivo << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(arquivo, linha)) {
        size_t comentario = linha.find('#');

        // string::npos = -1 = Não encontrado.
        if (comentario != string::npos) { 
            linha = linha.substr(0, comentario);
        }

        linha.erase(remove_if(linha.begin(), linha.end(), ::isspace), linha.end());

        if (!linha.empty()) {
            partes = dividir_instrucoes(linha);
            instrucoes.push_back(partes);
        }
    }

    arquivo.close();
    return instrucoes;
}