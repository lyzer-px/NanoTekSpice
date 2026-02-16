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
    //sections
    ".chipsets:",  // Defines chipsets
    ".links:",     // Links between components
    
    // special components
    "input",      // Input terminals
    "output",     // Output terminals
    "true",       // true component 
    "false",      // false component

    // basic components
    "and",        // AND gate logic
    "or",         // OR gate logic
    "xor",        // XOR gate logic
    "not",        // NOT (inverter) gate logic
    
    // gates components
    "4001",        // four NOR gates
    "4011",        // four NAND gates
    "4030",        // four XOR gates
    "4069",        // six INVERTER gates
    "4071",        // four OR gates
    "4081",        // four AND gates
    
    // advanced components
    "4008",       // 4 bits adder.
    "4013",       // Dual Flip Flop.
    "4017",       // 10 bits Johnson decade.
    "4040",       // 12 bits counter.
    "4094",       // 8 bits shift register.
    "4512",       // 8 channel data selector.
    "4514",       // 4 bits decoder.
    "4801",       // Random access memory.
    "2716",       // Read only memory (memory initiliazed from ./rom.bin).
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
        throw ParserFileException("Parser : Invalid file");
    while (std::getline(this->_stream, line)) {
        if (line[0] == '#') {
            continue;
        }
        strutils::sanitize(line);
        std::vector<std::string> tokens = strutils::splitStr(line, ' ');
        if (line == Keywords[0] && i == 0) {
            this->parsing_components_section = true;
            this->parsing_links_section = false;
            i++;
            continue;
        }
        if (line == Keywords[1] && i != 0) {
            this->parsing_links_section = true;
            this->parsing_components_section = false;
            continue;
        }
        if (this->parsing_components_section && ! this->parsing_links_section) {
            verifyChipsetSyntax(tokens);
            this->_chipsets.push_back(std::pair(tokens.at(0), tokens.at(1)));
            continue;
        }
        if (this->parsing_links_section && ! this->parsing_components_section) {
            std::vector<std::string> lft = strutils::splitStr(tokens.at(0), ':');
            std::vector<std::string> rght = strutils::splitStr(tokens.at(1), ':'); 
            verifyLinkSyntax(lft, rght);
            this->_links.push_back(Link(lft.at(0), lft.at(1), rght.at(0), rght.at(1)));
        }
    }
    if (this->_links.empty() || this->_chipsets.empty())
        throw ParserSyntaxException("Parser : Missing section"); 
}

void nts::Parser::verifyChipsetSyntax(std::vector<std::string> vec)
{
    if (vec.size() != 2)
        throw ParserSyntaxException("Parser : Invalid token amount");
    for (auto keyword : Keywords) {
        if (vec.at(0) == keyword)
            return;
    }
    throw ParserSyntaxException("Parser : Invalid component");
}

void nts::Parser::verifyLinkSyntax(std::vector<std::string> left, std::vector<std::string> right)
{
    if (left.size() != 2 || right.size() != 2)
        throw ParserSyntaxException("Parser : Invalid token amount");
    if (this->componentExists(left.at(0)) && this->componentExists(right.at(0)))
        return;
    throw ParserSyntaxException("Parser: Invalid chipset to link");
}

bool nts::Parser::componentExists(std::string str)
{
    for (auto chipset : this->_chipsets) {
        if (chipset.second == str)
            return true;
    }
    return false;
}
