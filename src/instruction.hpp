#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <cstdint>
#include <vector>
#include <utility>

using namespace std;

void formato_R(string opcode, string rd,  string rs1, string rs2);
void formato_U(string opcode, string rd,string imm);
void formato_I(string opcode, string rd,string rs1, string imm);
void formato_S(string opcode, string rs2,string offset_rs1);
char identificarFormato(const string& opcode);
void executarInstrucoes(vector<string> linha);

#endif // INSTRUCTION_HPP