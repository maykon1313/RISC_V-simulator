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
    
    Simulator() : memoria(32), registro() {
        instrucoes = lerInstrucoes("entrada2.txt");
    }

    void executar() {
        for (const auto& instrucao : instrucoes) {
            executarInstrucoes(instrucao);
        }
    }

};

/*
Simulator::Simulator() : Memory(), registers() {}

void Simulator::(const std::vector<std::string>& instructions) {
    for (const auto& instruction : instructions) {
        instructionMemory.push_back(instruction);
    }
}

void Simulator::execute() {
    for (const auto& instruction : instructionMemory) {
        executeInstruction(instruction);
    }
}

void Simulator::executeInstruction(const std::string& instruction) {
    std::vector<std::string> parts = splitInstruction(instruction);
    std::string opcode = parts[0];

    // Call the appropriate instruction handler based on the opcode
    if (opcode == "add" || opcode == "sub" || opcode == "mul") {
        handleRTypeInstruction(parts);
    } else if (opcode == "lw" || opcode == "sw") {
        handleITypeInstruction(parts);
    } else {
        std::cerr << "Unknown instruction: " << instruction << std::endl;
    }
}

std::vector<std::string> Simulator::splitInstruction(const std::string& instruction) {
    std::vector<std::string> parts;
    std::stringstream ss(instruction);
    std::string part;

    while (ss >> part) {
        parts.push_back(part);
    }

    return parts;
}

void Simulator::handleRTypeInstruction(const std::vector<std::string>& parts) {
    // Implementation for handling R-type instructions
}

void Simulator::handleITypeInstruction(const std::vector<std::string>& parts) {
    // Implementation for handling I-type instructions
}
*/