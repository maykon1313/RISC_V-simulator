#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

using namespace std;

// Função para dividir uma instrução em partes
vector<string> dividir_instrucoes(const string& instruction);

// Função para analisar uma linha de instrução e retornar um vetor de strings
vector<vector<string>> lerInstrucoes(const string& line);

// Função para verificar se uma string é um número
// bool isNumber(const string& s);

// Função para converter uma string hexadecimal em um inteiro
// int hexStringToInt(const string& hexStr);

#endif // PARSER_HPP