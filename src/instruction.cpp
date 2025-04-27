#include "instruction.hpp"
#include "registers.hpp"
#include "memory.hpp"
#include <iostream>

/*
#include <unordered_map>
#include <functional>

// Função para decodificar e executar instruções RISC-V
void executeInstruction(const std::string& opcode, const std::vector<std::string>& operands) {
    static std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> instructionMap = {
        {"add", [](const std::vector<std::string>& ops) {
            int rd = idxReg(ops[0]);
            int rs1 = idxReg(ops[1]);
            int rs2 = idxReg(ops[2]);
            regs[rd] = regs[rs1] + regs[rs2];
        }},
        {"sub", [](const std::vector<std::string>& ops) {
            int rd = idxReg(ops[0]);
            int rs1 = idxReg(ops[1]);
            int rs2 = idxReg(ops[2]);
            regs[rd] = regs[rs1] - regs[rs2];
        }},
        {"andi", [](const std::vector<std::string>& ops) {
            int rd = idxReg(ops[0]);
            int rs1 = idxReg(ops[1]);
            int imm = parseImm(ops[2]);
            regs[rd] = regs[rs1] & imm;
        }},
        {"ori", [](const std::vector<std::string>& ops) {
            int rd = idxReg(ops[0]);
            int rs1 = idxReg(ops[1]);
            int imm = parseImm(ops[2]);
            regs[rd] = regs[rs1] | imm;
        }},
        {"xori", [](const std::vector<std::string>& ops) {
            int rd = idxReg(ops[0]);
            int rs1 = idxReg(ops[1]);
            int imm = parseImm(ops[2]);
            regs[rd] = regs[rs1] ^ imm;
        }},
        {"lw", [](const std::vector<std::string>& ops) {
            int rd = idxReg(ops[0]);
            auto [offset, base] = parseOffsetBase(ops[1]);
            regs[rd] = memory[regs[base] + offset];
        }},
        {"sw", [](const std::vector<std::string>& ops) {
            int rs2 = idxReg(ops[0]);
            auto [offset, base] = parseOffsetBase(ops[1]);
            memory[regs[base] + offset] = regs[rs2];
        }},
        // Adicione mais instruções conforme necessário
    };

    auto it = instructionMap.find(opcode);
    if (it != instructionMap.end()) {
        it->second(operands);
    } else {
        std::cerr << "Instrução não reconhecida: " << opcode << std::endl;
    }
}
*/

void formato_R(string opcode, string rd,  string rs1, string rs2) {
    int rd_idx = stoi(rd.substr(1));
    int rs1_idx = stoi(rs1.substr(1));
    int rs2_idx = stoi(rs2.substr(1));

    if (opcode == "add") {
        regs.escrever_no_registro(rd_idx, regs.ler_no_registro(rs1_idx) + regs.ler_no_registro(rs2_idx));
    } else if (opcode == "sub") {
        regs.escrever_no_registro(rd_idx, regs.ler_no_registro(rs1_idx) - regs.ler_no_registro(rs2_idx));
    } else if (opcode == "xor") {

    } else if (opcode == "or") {

    } else if (opcode == "and") {

    } else if (opcode == "sll") {

    } else if (opcode == "srl") {

    } else if (opcode == "sra") {

    } else if (opcode == "slt") {

    } else if (opcode == "sltu") {

    } else {
        cerr << "Instrução não identificada: " << opcode << endl;
    }
}

void formato_U(string opcode, string rd,string imm) {
    int rd_idx = stoi(rd.substr(1));
    int32_t imm_val = stoi(imm);

    if (opcode == "lui") {
        regs.escrever_no_registro(rd_idx, imm_val << 12);
    } else if (opcode == "auipc") {

    } else {
        cerr << "Instrução não identificada: " << opcode << endl;
    }
}

void formato_I(string opcode, string rd,string rs1, string imm) {
    int rd_idx = stoi(rd.substr(1));
    int rs1_idx = stoi(rs1.substr(1));
    int32_t imm_val = stoi(imm);


    if (opcode == "addi") {

    } else if (opcode == "xori") {

    } else if (opcode == "ori") {

    } else if (opcode == "andi") {

    } else if (opcode == "slli") {

    } else if (opcode == "srli") {

    } else if (opcode == "srai") {

    } else if (opcode == "slti") {

    } else if (opcode == "sltiu") {

    } else if (opcode == "lb") {

    } else if (opcode == "lh") {

    } else if (opcode == "lw") {

    } else if (opcode == "lbu") {

    } else if (opcode == "lhu") {

    } else {
        cerr << "Instrução não identificada: " << opcode << endl;
    }
}

void formato_S(string opcode, string rs2,string offset_rs1) {
    int rs2_idx = stoi(rs2.substr(1));
    auto pos = offset_rs1.find('(');
    int offset = stoi(offset_rs1.substr(0, pos));
    int rs1_idx = stoi(offset_rs1.substr(pos + 2, offset_rs1.size() - pos - 3));

    if (opcode == "sb") {

    } else if (opcode == "sh") {

    } else if (opcode == "sw") {

    } else {
        cerr << "Instrução não identificada: " << opcode << endl;
    }
}

char identificarFormato(const string& opcode) {
    // Formato R
    if (opcode == "add" || opcode == "sub" || opcode == "xor" || opcode == "or" || opcode == "and" ||
        opcode == "sll" || opcode == "srl" || opcode == "sra" || opcode == "slt" || opcode == "sltu") {
        return 'R';
    }
    // Formato U
    else if (opcode == "lui" || opcode == "auipc") {
        return 'U';
    }
    // Formato I
    else if (opcode == "addi" || opcode == "xori" || opcode == "ori" || opcode == "andi" ||
             opcode == "slli" || opcode == "srli" || opcode == "srai" || opcode == "slti" || opcode == "sltiu" ||
             opcode == "lb" || opcode == "lh" || opcode == "lw" || opcode == "lbu" || opcode == "lhu") {
        return 'I';
    }
    // Formato S
    else if (opcode == "sb" || opcode == "sh" || opcode == "sw") {
        return 'S';
    }
    // Instrução desconhecida
    else {
        return 'D';
    }
}

void executarInstrucoes(vector<string> linha) {
    if (linha.empty()) {
        cerr << "Linha vazia passada para execução." << endl;
        return;
    }

    string opcode = linha[0], rd, rs1, rs2, imm, offset_rs1;
    char formato = identificarFormato(opcode);

    // Formato R (aritméticas e lógicas registro→registro):
    if (formato == 'R') {
        if (linha.size() < 4) {
            cerr << "Instrução incompleta." << endl;
            return;
        }

        rd = linha[1];
        rs1 = linha[2];
        rs2 = linha[3];

        formato_R(opcode, rd, rs1, rs2);
    }

    // Formato U (upper immediate):
    else if (formato == 'U') {
        if (linha.size() < 3) {
            cerr << "Instrução incompleta." << endl;
            return;
        }

        rd = linha[1];
        imm = linha[2];

        formato_U(opcode, rd, imm);
    }

    // Formato I (imediato; inclui addi e cargas de memória):
    else if (formato == 'I') {
        if (linha.size() < 4) {
            cerr << "Instrução incompleta." << endl;
            return;
        }

        rd = linha[1];
        rs1 = linha[2];
        imm = linha[3];

        formato_I(opcode, rd, rs1, imm);
    }

    // Formato S (armazenamento):
    else if (formato == 'S') {
        if (linha.size() < 3) {
            cerr << "Instrução incompleta." << endl;
            return;
        }

        rs2 = linha[1];
        offset_rs1 = linha[2];

        formato_S(opcode, rs2, offset_rs1);
    }

    // Instrução desconhecida:
    else {
        cerr << "Instrução não identificada: " << opcode << endl;
    }
}
