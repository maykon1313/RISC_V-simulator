#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <cstdint>
#include <vector>
#include <utility>

using namespace std;

/*
struct tipo_R {
    string opcode;
    int rd;
    int rs1;
    int rs2;
};

struct tipo_I{
    string opcode;
    int rd;
    int rs1;
    int32_t imm;
};

struct tipo_S{
    string opcode;
    int rs2;
    int32_t imm;
    int rs1;
};

struct tipo_U{
    string opcode;
    int rd;
    int32_t imm;
};


// Funções para decodificar instruções
RType decodeRType(const vector<string>& parts);
IType decodeIType(const vector<string>& parts);
SType decodeSType(const vector<string>& parts);
UType decodeUType(const vector<string>& parts);

// Função para executar instruções
void executeInstruction(const string& opcode, int rd, int rs1, int rs2);
void executeInstruction(const string& opcode, int rd, int rs1, int32_t imm);
void executeInstruction(const string& opcode, int rs2, int32_t imm, int rs1);
void executeInstruction(const string& opcode, int rd, int32_t imm);
*/

void formato_R(string opcode, string rd,  string rs1, string rs2);
void formato_U(string opcode, string rd,string imm);
void formato_I(string opcode, string rd,string rs1, string imm);
void formato_S(string opcode, string rs2,string offset_rs1);
char identificarFormato(const string& opcode);
void executarInstrucoes(vector<string> linha);

#endif // INSTRUCTION_HPP