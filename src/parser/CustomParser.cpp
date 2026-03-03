/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CustomParser
*/

#include "parser/CustomParser.hpp"

#include <algorithm>

#include "../../include/Exception/BadFileExtensionException.hpp"
#include "../../include/Exception/ChipsetAlreadyDefinedError.hpp"
#include "../../include/Exception/ChipsetArgumentError.hpp"
#include "../../include/Exception/ChipsetCommandNotFound.hpp"
#include "../../include/Exception/FileNotFoundException.hpp"
#include "../../include/Exception/LinkDefinitionSyntaxError.hpp"
#include "../../include/Exception/LinkNoPinNumber.hpp"
#include "../../include/Exception/LinkSyntaxError.hpp"
#include "../../include/Exception/LinkUnknownChipset.hpp"
#include "../../include/Exception/NoChipsetError.hpp"
#include "../../include/Exception/PinNumberIsInteger.hpp"
#include "../../include/Exception/UnknownChipsetType.hpp"
#include "../../include/Utils/StringUtils.hpp"

namespace nts {
const std::vector<std::string> CHIPSET_TYPES = {
    ".chipsets:",
    ".links:",
    "input",
    "output",
    "true",
    "false",
    "and",
    "or",
    "xor",
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
    "half_adder",
    "ah_sr_latch",
    "d_latch",
    "full_adder",
    ""
};

CustomParser::CustomParser() noexcept
{}

CustomParser::CustomParser(std::string filename) noexcept: _filename{std::move(
    filename)}
{}

void CustomParser::parse()
{
    if (_filename.empty())
        throw error::FileNotFoundException();

    parse(_filename);
}

void CustomParser::parse(const std::string &filename)
{
    _filename = filename;
    openFile();

    findChipsetCommand();

    parseChipsets();

    parseLinks();
}

ParsedChipsets CustomParser::getChipsets() const noexcept
{
    return _chipsets;
}

std::vector<Link> CustomParser::getLinks() const noexcept
{
    return _links;
}

void CustomParser::openFile()
{
    if (!_filename.ends_with(".nts"))
        throw error::BadFileExtensionException();

    _stream = std::ifstream{_filename};

    if (!_stream.is_open())
        throw error::FileNotFoundException();
}

std::vector<std::string> CustomParser::preprocessLine()
{
    ++_lineNumber;
    auto tempLine = utils::StringUtils::cleanString(_line);

    if (tempLine.empty() || tempLine.at(0) == '#')
        return std::vector<std::string>{};

    tempLine = sanitize(tempLine);

    return utils::StringUtils::split(tempLine);
}

void CustomParser::findChipsetCommand()
{
    while (std::getline(_stream, _line)) {
        const std::vector<std::string> words = preprocessLine();
        if (words.empty())
            continue;

        if (words.size() != 1)
            throw error::ChipsetCommandNotFound(_filename, _line, _lineNumber);

        if (words.at(0) == ".chipsets:")
            return;
        break;
    }

    throw error::ChipsetCommandNotFound(_filename, _line, _lineNumber);
}

std::string CustomParser::sanitize(std::string &str)
{
    for (std::size_t i = 0; i < str.size(); ++i)
        if (str.at(i) == '#') {
            str.erase(i);
            return str;
        }

    return str;
}

void CustomParser::checkChipsetType(const std::vector<std::string> &words)
{
    if (std::ranges::find(CHIPSET_TYPES, words[0]) == CHIPSET_TYPES.end())
        throw error::UnknownChipsetType(_filename, _line, _lineNumber);
}

bool CustomParser::checkChipsetName(const std::vector<std::string> &words)
{
    if (words.size() == 1 && words[0] == ".links:")
        return false;

    if (words.size() < 2)
        throw error::ChipsetArgumentError(words.size() > 2, _filename, _line,
            _lineNumber);

    if (words.size() > 2)
        throw error::ChipsetArgumentError(words.size() > 2, _filename, _line,
            _lineNumber);

    const auto &temp = std::ranges::find_if(_chipsets,
        [words](const ParsedChipset &chipset) {
            return words[1] == chipset.second;
        });

    if (temp != _chipsets.end())
        throw error::ChipsetAlreadyDefinedError(_filename, _line, _lineNumber);

    return true;
}

void CustomParser::parseChipsets()
{
    while (std::getline(_stream, _line)) {
        std::vector<std::string> words = preprocessLine();
        if (words.empty())
            continue;

        checkChipsetType(words);

        if (checkChipsetName(words))
            _chipsets.emplace_back(std::pair{words[0], words[1]});
        else
            break;
    }
}

void CustomParser::checkLink(const bool isFirst, const std::string &str)
{
    if (std::count(str.begin(), str.end(), ':') != 1)
        throw error::LinkDefinitionSyntaxError(isFirst, _filename, _line,
            _lineNumber);

    const std::vector<std::string> words = utils::StringUtils::split(str, ':');
    if (words[0].empty())
        throw error::LinkDefinitionSyntaxError(isFirst, _filename, _line,
            _lineNumber);

    const auto chipset = std::ranges::find_if(_chipsets,
        [words](const ParsedChipset &item) {
            return words[0] == item.second;
        });
    if (chipset == _chipsets.end())
        throw error::LinkUnknownChipset(isFirst, _filename, _line, _lineNumber);

    if (words.size() == 1)
        throw error::LinkNoPinNumber(isFirst, _filename, _line, _lineNumber);

    try {
        std::stol(words[1]);
    } catch (const std::exception &) {
        throw error::PinNumberIsInteger(isFirst, _filename, _line, _lineNumber);
    }
}

void CustomParser::parseLinks()
{
    if (_chipsets.empty())
        throw error::NoChipsetError(_filename, _line, _lineNumber);

    while (std::getline(_stream, _line)) {
        std::vector<std::string> words = preprocessLine();
        if (words.empty())
            continue;

        if (words.size() != 2)
            throw error::LinkSyntaxError(_filename, _line, _lineNumber);

        checkLink(true, words[0]);
        checkLink(false, words[1]);

        CustomParser::registerLink(words);
    }
}

void CustomParser::registerLink(const std::vector<std::string> &words)
{
    auto node1 = utils::StringUtils::split(words[0], ':');
    auto node2 = utils::StringUtils::split(words[1], ':');

    _links.emplace_back(node1[0], node1[1], node2[0], node2[1]);
}
} // namespace nts
