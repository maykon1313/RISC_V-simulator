#include "memory.hpp"
#include <iostream>
#include <cstdint>

Memory::Memory(size_t size) : memory(size, 0) {}

void Memory::erro_de_memoria(size_t address) const {
    if (address >= memory.size()) {
        std::cerr << "Tentativa de acesso fora dos limites da memória: endereço " << address << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

uint8_t Memory::ler_na_memoria(size_t address) const {
    erro_de_memoria(address);
    return memory[address];
}

void Memory::escrever_na_memoria(size_t address, uint8_t value) {
    erro_de_memoria(address);
    memory[address] = value;
}