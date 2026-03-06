/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "parser/Parser.hpp"

#include <array>
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#include "Exception/LinkCommandNotFound.hpp"
#include "Exception/ParsingTooManyTokens.hpp"
#include "StringUtils.hpp"
#include "Exception/Exceptions.hpp"


namespace nts {

const std::vector<nts::Token> KEYWORDS = {
    ".chipsets:",
    ".links:",
    "input",
    "output",
    "true",
    "false",
    "clock",
    "and",
    "nand",
    "or",
    "nor",
    "xor",
    "xnor",
    "not",
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

Link::Link(const ChipsetName &chipset1Name, std::size_t chipset1Pin,
    const ChipsetName &chipset2Name, std::size_t chipset2Pin)
{
    this->component1.second = chipset1Pin;
    this->component2.second = chipset2Pin;
    this->component1.first  = chipset1Name;
    this->component2.first  = chipset2Name;
}

Parser::Parser(const std::string &filename) noexcept:
     _filename{filename}, _parsingComponentsSection{false},
    _parsingLinksSection{false}
{
    this->_stream = std::ifstream(filename);
}

bool Parser::toggleParsingSections(std::vector<std::string> tokens, size_t &index)
{
    if (tokens.at(0) == KEYWORDS.at(0) && index == 0) {
        this->_parsingComponentsSection = true;
        this->_parsingLinksSection      = false;
        index++;
        return true;
    }
    if (tokens.at(0) == KEYWORDS.at(1) && index != 0) {
        this->_parsingLinksSection      = true;
        this->_parsingComponentsSection = false;
        return true;
    }
    return false;
}

bool Parser::pushToChipsets(std::vector<std::string> tokens)
{
    if (this->_parsingComponentsSection && !this->_parsingLinksSection) {
        verifyChipsetSyntax(tokens);
        if (this->componentExists(tokens.at(1)))
            throw error::ChipsetAlreadyDefinedError(this->_filename, this->_currentLine,
                                                    this->_currentLineIndex);
        this->_chipsets.emplace_back(tokens.at(0), tokens.at(1));
        return true;
    }
    return false;
}

void Parser::pushToLinks(std::vector<std::string> tokens)
{
    std::size_t pin1 = 0;
    std::size_t pin2 = 0;

    if (this->_parsingLinksSection && !this->_parsingComponentsSection) {
        std::vector<std::string> left =
            strutils::splitStr(tokens.at(0), ':');
        std::vector<std::string> right = strutils::splitStr(tokens.at(1),
            ':');
        verifyLinkSyntax(left, right);
        try {
            pin1 = std::stoul(left.at(1));
        } catch (std::exception) {
            throw error::LinkNoPinNumber(false, this->_filename, this->_currentLine,
                                         this->_currentLineIndex);
        }
        try {
            pin2 = std::stoul(right.at(1));
        } catch (std::exception) {
            throw error::LinkNoPinNumber(true, this->_filename, this->_currentLine,
                                         this->_currentLineIndex);
        }
        this->_links.emplace_back(left.at(0), pin1, right.at(0), pin2);
    }
}

void Parser::parse()
{
    std::string line;
    std::size_t index = 0;

    while (std::getline(this->_stream, line)) {
        this->_currentLineIndex++;
        this->_currentLine = line;
        if (line[0] == '#' || line.empty()) {
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

void Parser::start()
{
    if (this->_stream.fail())
        throw error::FileNotFoundException();
    this->parse();
    if (this->_chipsets.empty())
        throw error::ChipsetArgumentError(false, this->_filename,
                                          this->_currentLine,
                                          this->_currentLineIndex);
    if (this->_links.empty())
        throw error::LinkCommandNotFound(this->_filename,
                                         this->_currentLine,
                                         this->_currentLineIndex);
}

std::vector<std::pair<ChipsetType, ChipsetName>>
    Parser::getChipsets() const noexcept
{
    return this->_chipsets;
}

std::vector<Link> Parser::getLinks() const noexcept
{
    return this->_links;
}

void Parser::verifyLinkSyntax(const std::vector<std::string> &left,
    const std::vector<std::string> &right)
{
    if (left.size() != 2 || right.size() != 2)
        throw error::ParsingTooManyTokens(this->_filename, this->_currentLine, this->_currentLineIndex);
    if (this->componentExists(left.at(0)) && this->componentExists(right.at(0)))
        return;
    throw error::LinkSyntaxError(this->_filename,
                                 this->_currentLine, this->_currentLineIndex);
}

void Parser::verifyChipsetSyntax(const std::vector<std::string> &tokens)
{
    if (tokens.size() != 2)
        throw error::ParsingTooManyTokens(this->_filename, this->_currentLine, this->_currentLineIndex);
    for (const auto &keyword: KEYWORDS) {
        if (tokens.at(0) == keyword)
            return;
    }
    throw error::UnknownChipsetType(this->_filename, this->_currentLine,
                                    this->_currentLineIndex);
}

bool Parser::componentExists(const std::string &str)
{
    for (const auto &chipsetName: this->_chipsets | std::views::values) {
        if (chipsetName == str)
            return true;
    }
    return false;
}

}
