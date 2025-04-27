#include "registers.hpp"
#include <array>
#include <stdexcept>

using namespace std;

class Registers {
public:
    Registers() {
        for (auto& reg : regs) {
            reg = 0;
        }
    }

    uint32_t ler_no_registro (int index) const {
        erro_no_registro(index);
        return regs[index];
    }

    void escrever_no_registro (int index, uint32_t value) {
        erro_no_registro(index);
        regs[index] = value;
    }

private:
    array<uint32_t, 32> regs;

    void erro_no_registro (int index) const {
        if (index < 0 || index >= 32) {
            throw out_of_range("Register index out of range");
        }
    }
};