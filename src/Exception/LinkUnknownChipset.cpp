/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkUnknownChipset
*/

#include "../../include/Exception/LinkUnknownChipset.hpp"

#include <sstream>

#include "../Utils/StringUtils.hpp"

namespace nts {
namespace error {
LinkUnknownChipset::LinkUnknownChipset(const bool &first,
    const std::string &filename, const std::string &line,
    const std::size_t &lineNumber): ParsingException
    {filename, line, lineNumber}, _first{first}
{
    _message   = "Chipset name not registered";
    _errorCode = "[Link-Unknown-Chipset]";

    std::stringstream stream;
    stream << "  " << _lineNumber << " | " << _line;

    _errorDescription = stream.str();

    stream.str(_line);
    std::string temp;
    stream >> temp;

    if (!_first)
        stream >> temp;

    _cursorPosition = _line.find(temp) +
        utils::StringUtils::beginSpacesCount(temp);
    _underlineSize = getUnderlineSize(utils::StringUtils::split(temp, ':')[0]);
}
} // error
} // nts
