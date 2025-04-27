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
    Simulator();
    void lerInstrucoes (const vector<string>& instructions);
    void execute();
    void reset();

private:
    Memory memory;
    Registers registers;
    vector<Instruction> instructionSet;
    size_t programCounter;

    void fetch();
    void decode(const Instruction& instruction);
    void executeInstruction(const Instruction& instruction);
};

#endif // SIMULATOR_HPP