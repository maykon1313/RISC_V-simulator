#ifndef REGISTERS_HPP
#define REGISTERS_HPP

#include <array>
#include <cstdint>
#include <stdexcept>

using namespace std;

class Registers {
public:
    Registers();

    uint32_t ler_no_registro (int index) const;
    void escrever_no_registro (int index, uint32_t value);

private:
    // 32 registers (x0 to x31)
    array<uint32_t, 32> regs; 
};

#endif // REGISTERS_HPP