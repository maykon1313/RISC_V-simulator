#include "utils/parser.hpp"
#include "simulator.hpp"
#include "instruction.hpp"
#include "memory.hpp"
#include "registers.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Simulator {
    public:
    vector<vector<string>> instrucoes;
    Memory memoria;
    Registers registro;
    
    Simulator(const string& entrada) : memoria(32), registro() {
        instrucoes = lerInstrucoes(entrada);
    }

    void executar() {
        for (const auto& instrucao : instrucoes) {
            executarInstrucoes(instrucao);
        }
    }

};