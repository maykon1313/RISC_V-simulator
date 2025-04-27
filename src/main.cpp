#include <iostream>
#include "simulator.hpp"

int main() {
    Simulator simulator;

    if (!simulator.loadInstructions("instructions.txt")) {
        
        return 1;
    }

    simulator.execute(); // Start the execution loop

    return 0;
}