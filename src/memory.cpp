#include "memory.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdint>

using namespace std;

class Memory {
public:
    Memory(size_t size) : memory(size, 0) {}

    void erro_de_memoria (size_t address) {
        if (address >= memory.size()) {
            throw out_of_range("Memory read out of bounds");
        }
    }

    uint8_t ler_na_memoria (size_t address) {
        erro_de_memoria(address);
        return memory[address];
    }

    void escrever_na_memoria (size_t address, uint8_t value) {
        erro_de_memoria(address); 
        memory[address] = value;
    }

private:
    vector<uint8_t> memory;
};