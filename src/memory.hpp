#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <vector>
#include <cstdint>

class Memory {
public:
    Memory(size_t size);

    uint8_t ler_na_memoria(size_t address) const;
    void escrever_na_memoria(size_t address, uint8_t value);

private:
    void erro_de_memoria(size_t address) const;

    std::vector<uint8_t> memory;
};

#endif // MEMORY_HPP