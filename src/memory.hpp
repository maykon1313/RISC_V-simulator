class Memory {
public:
    Memory(size_t size);

    void erro_de_memoria (size_t address);
    uint8_t ler_na_memoria (size_t address);
    void escrever_na_memoria (size_t address, uint8_t value);
    // uint32_t readWord(size_t address) const;
    // void writeWord(size_t address, uint32_t value);
    // void loadFromFile(const std::string& filename, size_t startAddress);

private:
    std::vector<uint8_t> memory;
    size_t size;
};