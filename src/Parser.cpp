/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
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
    std::string line;

    while (std::getline(this->_stream, line)) {
        if (line[0] == '#')
            continue;
        this->sanitize(line);
        std::vector<std::string> tokens = this->splitStr(line, ' ');
        #ifdef DEBUG
            std::cout << "line: \""<< line << "\"" << std::endl;  
        #endif
        this->verifySyntax(tokens);
        this->addToCircuit(tokens);
    }
    if (this->has_components_section == false || this->has_links_section == false)
        throw ParserFileException("Invalid file format");
}

void nts::Parser::addToCircuit(std::vector<std::string>)
{
    return;
}

void nts::Parser::sanitize(std::string &str) const
{
    std::regex whitespaces("[\\s]+");
    str = std::regex_replace(str, whitespaces, " ");
}

std::vector<std::string> nts::Parser::splitStr(std::string &str, char delimiter) const
{
    std::vector<std::string> tokens;
    std::stringstream stream(str);
    std::string token;

    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void nts::Parser::verifySyntax(std::vector<std::string> tokens)
{
    for (auto token : tokens) {
        for (size_t i = 0; Keywords[i] != ""; i++) {
            if (! this->has_components_section && tokens.at(0) == Keywords[1]) {
                this->has_components_section = true;
                return;
            }
            if (! this->has_links_section && tokens.at(0) == Keywords[1]) {
                this->has_links_section = true;
                return;
            }
            if (std::find(token.begin(), token.end() Keywords[i])) 
                return;
        }
    }
   throw ParserSyntaxException("Parser : invalid token");
}
