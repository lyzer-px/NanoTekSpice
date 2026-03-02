/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "parser/Parser.hpp"

#include <array>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <regex>
#include <string>
#include <vector>

#include "StringUtils.hpp"

constexpr std::size_t NUMBER_OF_KEYWORDS                  = 28;
const std::array<nts::Token, NUMBER_OF_KEYWORDS> KEYWORDS = {
    ".chipsets:",
    ".links:",
    "input",
    "output",
    "true",
    "false",
    "and",
    "nand",
    "or",
    "xor",
    "xnor",
    "not",
    "nand",
    "4001",
    "4011",
    "4030",
    "4069",
    "4071",
    "4081",
    "4008",
    "4013",
    "4017",
    "4040",
    "4094",
    "4512",
    "4514",
    "4801",
    "2716",
    ""
};

nts::Link::Link(const ChipsetName &chipset1Name, const std::string &chipset1Pin,
    const ChipsetName &chipset2Name, const std::string &chipset2Pin)
{
    this->component1.first  = chipset1Name;
    this->component1.second = std::stoul(chipset1Pin);
    this->component2.first  = chipset2Name;
    this->component2.second = std::stoul(chipset2Pin);
}

nts::Parser::Parser(const std::string &filename) noexcept:
    _parsingComponentsSection{false},
    _parsingLinksSection{false}, _badExtention{false}
{
    if (!filename.ends_with(".nts")) {
        this->_badExtention = true;
        return;
    }
    this->_stream = std::ifstream(filename);
}

void nts::Parser::start()
{
    std::string line;
    std::size_t itt = 0;

    if (this->_stream.fail() || this->_badExtention)
        throw ParserFileException("Parser : Invalid file");
    while (std::getline(this->_stream, line)) {
        if (line[0] == '#') {
            continue;
        }
        strutils::sanitize(line);
        std::vector<std::string> tokens = strutils::splitStr(line, ' ');
        if (tokens[0] == KEYWORDS[0] && itt == 0) {
            this->_parsingComponentsSection = true;
            this->_parsingLinksSection      = false;
            itt++;
            continue;
        }
        if (tokens[0] == KEYWORDS[1] && itt != 0) {
            this->_parsingLinksSection      = true;
            this->_parsingComponentsSection = false;
            continue;
        }
        if (this->_parsingComponentsSection && !this->_parsingLinksSection) {
            verifyChipsetSyntax(tokens);
            // @todo: use @c{std::vector::emplace_back} instead
            this->_chipsets.push_back(std::pair(tokens.at(0), tokens.at(1)));
            continue;
        }
        if (this->_parsingLinksSection && !this->_parsingComponentsSection) {
            std::vector<std::string> left =
                strutils::splitStr(tokens.at(0), ':');
            std::vector<std::string> right = strutils::splitStr(tokens.at(1),
                ':');
            verifyLinkSyntax(left, right);
            // @todo: use @c{std::vector::emplace_back} instead
            this->_links.push_back(Link(left.at(0), left.at(1), right.at(0),
                right.at(1)));
        }
    }
    if (this->_links.empty() || this->_chipsets.empty())
        throw ParserSyntaxException("Parser : Missing section");
}

std::vector<std::pair<nts::ChipsetType, nts::ChipsetName>>
    nts::Parser::getChipsets() const noexcept
{
    return this->_chipsets;
}

std::vector<nts::Link> nts::Parser::getLinks() const noexcept
{
    return this->_links;
}

void nts::Parser::verifyLinkSyntax(const std::vector<std::string> &left,
    const std::vector<std::string> &right)
{
    if (left.size() != 2 || right.size() != 2)
        throw ParserSyntaxException("Parser : Invalid token amount");
    if (this->componentExists(left.at(0)) && this->componentExists(right.at(0)))
        return;
    throw ParserSyntaxException("Parser: Invalid chipset to link");
}

void nts::Parser::verifyChipsetSyntax(const std::vector<std::string> &tokens)
{
    if (tokens.size() != 2)
        throw ParserSyntaxException("Parser : Invalid token amount");
    for (const auto &keyword: KEYWORDS) {
        if (tokens.at(0) == keyword)
            return;
    }
    throw ParserSyntaxException("Parser : Invalid component");
}

bool nts::Parser::componentExists(const std::string &str)
{
    for (const auto &chipsetName: this->_chipsets | std::views::values) {
        if (chipsetName == str)
            return true;
    }
    return false;
}
