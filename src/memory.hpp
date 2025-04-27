using namespace std;

class Memory {
public:
    Memory(size_t size);

    void erro_de_memoria (size_t address);
    uint8_t ler_na_memoria (size_t address);
    void escrever_na_memoria (size_t address, uint8_t value);

private:
    vector<uint8_t> memory;
    size_t size;
};