#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "instruction.hpp"
#include "memory.hpp"
#include "registers.hpp"
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

class Simulator {
public:
    Simulator(const string& entrada);
    void executar();

private:
    vector<vector<string>> instrucoes;
    Memory memoria;
    Registers registro;
    uint32_t PC_counter;
};

#endif // SIMULATOR_HPP