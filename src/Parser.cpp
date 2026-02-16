/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include "Parser.hpp"
#include "StringUtils.hpp"

const nts::token Keywords[] = {
    ".chipsets:",  // Defines chipsets
    ".links:",     // Links between components
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

nts::Parser::Parser(const std::string &filename) noexcept
{
    if (!filename.ends_with(".nts")) {
        this->bad_extention = true;
        return;
    }
    this->_stream = std::ifstream(filename);
}

void nts::Parser::start()
{
    std::string line;
    std::size_t i = 0;

    if (this->_stream.fail() || this->bad_extention)
        throw ParserFileException("Invalid file");
    while (std::getline(this->_stream, line)) {
        if (line[0] == '#')
            continue;

        strutils::sanitize(line);
        std::vector<std::string> tokens = strutils::splitStr(line, ' ');
        verifySyntax(tokens);

        if (line == Keywords[0] && i == 0) {
            this->has_components_section = true;
            i++;
            continue;
        }
        if (line == Keywords[1] && i != 0) {
            this->has_links_section = true;
            continue;
        }
        if (this->has_components_section && ! this->has_links_section) {
            this->_chipsets.push_back(std::pair(tokens.at(0), tokens.at(1)));
            continue;
        }
        std::vector<std::string> lft = strutils::splitStr(tokens.at(0), ':');
        std::vector<std::string> rght = strutils::splitStr(tokens.at(1), ':'); 
        try {
            this->_links.push_back(Link(lft.at(0), lft.at(1), rght.at(0), rght.at(1)));
        } catch (std::exception &e) {
            throw ParserSyntaxException("Invalid pin");
        }
    }
    if (this->_links.empty())
        throw ParserSyntaxException("Missing section"); 
}

void nts::Parser::verifySyntax(std::vector<std::string> tokens)
{
    for (auto token : tokens) {
        for (size_t i = 0; Keywords[i] != ""; i++) {
            if (token.substr(0, Keywords[i].length()).find(Keywords[i]) !=
                std::string::npos) 
                return;
        }
    }
   throw ParserSyntaxException("Parser : invalid token");
}
