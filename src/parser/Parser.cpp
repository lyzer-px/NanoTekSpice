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
#include <stdexcept>
#include <string>
#include <vector>

#include "Exception/BadFileExtensionException.hpp"
#include "Exception/UnknownChipsetType.hpp"
#include "Exception/LinkSyntaxError.hpp"
#include "Exception/ChipsetAlreadyDefinedError.hpp"
#include "Exception/FileNotFoundException.hpp"
#include "Exception/ChipsetArgumentError.hpp"
#include "StringUtils.hpp"

const std::vector<nts::Token> KEYWORDS = {
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
     _filename{filename}, _badExtention{false},
    _parsingComponentsSection{false},
    _parsingLinksSection{false}
{
    if (!filename.ends_with(".nts")) {
        this->_badExtention = true;
        return;
    }
    this->_stream = std::ifstream(filename);
}


bool nts::Parser::toggleParsingSections(std::vector<std::string> tokens, size_t &index)
{
    if (tokens[0] == KEYWORDS[0] && index == 0) {
        this->_parsingComponentsSection = true;
        this->_parsingLinksSection      = false;
        index++;
        return true;
    }
    if (tokens[0] == KEYWORDS[1] && index != 0) {
        this->_parsingLinksSection      = true;
        this->_parsingComponentsSection = false;
        return true;
    }
    return false;
}

bool nts::Parser::pushToChipsets(std::vector<std::string> tokens)
{
    if (this->_parsingComponentsSection && !this->_parsingLinksSection) {
        verifyChipsetSyntax(tokens);
        if (this->componentExists(tokens.at(0)))
            throw error::ChipsetAlreadyDefinedError(this->_filename, this->_currentLine,
                                                    this->_currentLineIndex);
        this->_chipsets.emplace_back(tokens.at(0), tokens.at(1));
        return true;
    }
    return false;
}

void nts::Parser::pushToLinks(std::vector<std::string> tokens)
{
    if (this->_parsingLinksSection && !this->_parsingComponentsSection) {
        std::vector<std::string> left =
            strutils::splitStr(tokens.at(0), ':');
        std::vector<std::string> right = strutils::splitStr(tokens.at(1),
            ':');
        verifyLinkSyntax(left, right);
        this->_links.emplace_back(left.at(0), left.at(1), right.at(0),
            right.at(1));
    }
}

void nts::Parser::parse()
{
    std::string line;
    std::size_t index = 0;

    while (std::getline(this->_stream, line)) {
        this->_currentLineIndex++;
        this->_currentLine = line;
        if (line[0] == '#') {
            continue;
        }
        strutils::sanitize(line);
        std::vector<std::string> tokens = strutils::splitStr(line, ' ');
        if (this->toggleParsingSections(tokens, index))
            continue;
        if (this->pushToChipsets(tokens))
            continue;
        this->pushToLinks(tokens);
    }
}

void nts::Parser::start()
{
    if (this->_stream.fail())
        throw error::FileNotFoundException();
    if (this->_badExtention)
        throw error::BadFileExtensionException();
    this->parse();
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
    throw error::LinkSyntaxError(this->_filename,
                                 this->_currentLine, this->_currentLineIndex);
}

void nts::Parser::verifyChipsetSyntax(const std::vector<std::string> &tokens)
{
    if (tokens.size() != 2)
        throw ParserSyntaxException("Parser : Invalid token amount");
    for (const auto &keyword: KEYWORDS) {
        if (tokens.at(0) == keyword)
            return;
    }
    throw error::UnknownChipsetType(this->_filename, this->_currentLine,
                                    this->_currentLineIndex);
}

bool nts::Parser::componentExists(const std::string &str)
{
    for (const auto &chipsetName: this->_chipsets | std::views::values) {
        if (chipsetName == str)
            return true;
    }
    throw error::ChipsetArgumentError(false, this->_filename, this->_currentLine,
                                      this->_currentLineIndex);
}
