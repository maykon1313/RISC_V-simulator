#include "simulator.hpp"
#include "utils/parser.hpp"
#include "instruction.hpp"
#include "memory.hpp"
#include "registers.hpp"
#include <iostream>
#include <array>
#include <cstdint>

Simulator::Simulator(const std::string& entrada) 
    : memoria(Memory()), registro(Registers()), PC_counter(0) {
    instrucoes = lerInstrucoes(entrada);
}

void Simulator::executar() {
    for (; PC_counter < instrucoes.size(); PC_counter++) {
        executarInstrucoes(instrucoes[PC_counter], Simulator::registro, Simulator::memoria, PC_counter);
    }
}

void Simulator::estado() {
    // Exibir os valores dos registradores
    array<uint32_t, 32> registros = Simulator::registro.regs;
    cout << "Estado dos registradores:" << endl;
    for (int i = 0; i < registros.size(); i++) {
        if (registros[i] != 0) { // Exibir apenas registradores com valores diferentes de zero
            cout << "t" << i << " = " << registros[i] << endl;
        }
    }

    // Exibir os valores da memória
    map<size_t, uint8_t> memorias = Simulator::memoria.memory;
    cout << "\nEstado da memória:" << endl;
    for (const auto& [index, value] : memorias) {
        if (value != 0) { // Exibir apenas endereços de memória com valores diferentes de zero
            cout << "mem(" << index << ") = " << static_cast<int>(value) << endl;
        }
    }
}