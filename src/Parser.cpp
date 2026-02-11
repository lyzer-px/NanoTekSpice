/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include <fstream>
#include <sstream>
#include <vector>
#include "Circuit.hpp"
#include "Parser.hpp"

const nts::token Keywords[] = {
    ".chipsets",  // Defines chipsets
    ".links",     // Links between components
    "input",      // Input terminals
    "i",           // input name ex: i0, i1 etc...
    "output",     // Output terminals
    "and",        // AND gate logic
    "nand",       // NAND gate logic
    "or",         // OR gate logic
    "nor",        // NOR gate logic
    "xor",        // XOR gate logic
    "not",        // NOT (inverter) gate logic
    "4008",       // 4 bits adder
    "4013",       // Dual Flip Flop
    "4017",       // 10 bits Johnson decade
    "4040",       // 12 bits counter
    "4094",       // 8 bits shift register
    "4512",       // 8 channel data selector
    "4514",       // 4 bits decoder
    "4801",       // Random access memory
    "2716",       // Read-only memory (initialized from ./rom.bin)
    "4027",       // Dual D Flip Flop
    "4050",       // Buffer (Hex buffer IC)
    "4060",       // 14-bit binary counter
    "4075",       // AND-NAND gates
    "4085",       // XOR-OR gates
    "4501",       // Multiplexer (8-channel)
    "4502",       // Demultiplexer (8-channel)
    "4555",       // Monostable multivibrator
    "7400",       // Quad 2-input NAND gate
    "7402",       // Quad 2-input NOR gate
    "7404",       // Hex inverter
    "7408",       // Quad 2-input AND gate
    "7410",       // Triple 3-input NAND gate
    "7413",       // Dual 4-input NAND gate
    "7417",       // Hex buffer/driver
    "7432",       // Quad 2-input OR gate
    "7450",       // Quad 2-input NOR gate
    "7474",       // Dual D-type flip-flop
    "7476",       // Dual JK flip-flop
    "7486",       // Quad 2-input XOR gate
    "7490",       // Decade counter
    "7493",        // 4-bit binary counter
    ""            //sentinel  
};

nts::Parser::Parser(const std::string &filename)
{
    this->_stream = std::ifstream(filename);

    if (this->_stream.fail())
        throw ParserFileException();
}

nts::Parser::~Parser() noexcept
{
    if (this->_stream.is_open())
        this->_stream.close();
}

void nts::Parser::start()
{
    char line[MAX_INPUT];
    bool has_components_section = false;
    bool has_links_section = false;

    while (this->_stream.getline(line, MAX_INPUT)) {
        if (line[0] == '#')
            continue;
        std::string sanitized = this->sanitize(line);
        std::vector<std::string> tokens = this->splitStr(sanitized);
        if (! has_components_section && tokens.at(0) == Keywords[1])
            has_components_section = true;
        if (! has_links_section && tokens.at(0) == Keywords[1])
            has_links_section = true;
        this->addToCircuit(tokens);
    }
    if (has_components_section == false || has_links_section == false)
        throw ParserFileException("Invalid file format");
}

std::string nts::Parser::sanitize(const char *line) const
{
    std::string sanitized = line;

    sanitized.replace(sanitized.begin(), sanitized.end(), '\t', ' ');
    return sanitized;
}

std::vector<std::string> nts::Parser::splitStr(std::string str) const
{
    std::vector<std::string> vec;
    std::size_t len = str.length();
    std::size_t pos = 0;  

    do {
        std::size_t delim_index = str.find(" ");
        vec.push_back(str.substr(pos, delim_index));
        pos += delim_index;
    } while (pos != len);
    return vec;
}

void nts::Parser::verifySyntax(std::vector<std::string> vec) const
{
    for (auto token : vec) {
        if (! Keywords->find(token) && token[0] != 'i')
            throw ParserSyntaxException("Parser : invalid token");
    }
}
