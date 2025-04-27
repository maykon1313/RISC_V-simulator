#include "simulator.hpp"
#include "utils/parser.hpp"
#include "instruction.hpp"
#include "memory.hpp"
#include "registers.hpp"
#include <iostream>
#include <array>

Simulator::Simulator(const std::string& entrada) 
    : memoria(Memory(32)), registro(Registers()), PC_counter(0) {
    instrucoes = lerInstrucoes(entrada);
}

void Simulator::executar() {
    for (; PC_counter < instrucoes.size(); PC_counter++) {
        executarInstrucoes(instrucoes[PC_counter], Simulator::registro, Simulator::memoria);
    }
}

void Simulator::estado() {
    array<uint32_t, 32> registro = Simulator::registro.regs;
    for (int i = 0; i < registro.size(); i++) {
        cout << "Registro " << i << ": " << registro[i] << endl;
    }
}