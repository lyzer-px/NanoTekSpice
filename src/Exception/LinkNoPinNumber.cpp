/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkNoPinNumber
*/

#include "../../include/Exception/LinkNoPinNumber.hpp"

#include <sstream>

#include "../Utils/StringUtils.hpp"

namespace nts {
namespace error {
LinkNoPinNumber::LinkNoPinNumber(const bool &first, const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    ParsingException{filename, line, lineNumber}, _first{first}
{
    _message   = "No pin number provided for link definition";
    _errorCode = "[Link-No-Pin-Number]";

    std::stringstream stream;
    stream << "  " << _lineNumber << " | " << _line;

    _errorDescription = stream.str();

    stream.str(_line);
    std::string temp;
    stream >> temp;

    _cursorPosition = _line.find(":") + 1;
    if (!_first)
        _cursorPosition = _line.find(":", _cursorPosition) + 1;
}
} // error
} // nts
