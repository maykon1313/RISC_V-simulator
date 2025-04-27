#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <vector>
#include <string>
#include "instruction.hpp"
#include "memory.hpp"
#include "registers.hpp"

using namespace std;

class Simulator {
public:
    Simulator(const string& entrada);
    void executar();

private:
    vector<vector<string>> instrucoes;
    Memory memoria;
    Registers registro;
};

#endif // SIMULATOR_HPP