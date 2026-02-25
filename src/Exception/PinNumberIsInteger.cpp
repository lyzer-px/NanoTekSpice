/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** PinNumberIsInteger
*/

#include "../../include/Exception/PinNumberIsInteger.hpp"

#include <sstream>

namespace nts {
namespace error {
PinNumberIsInteger::PinNumberIsInteger(const bool &first,
    const std::string &filename, const std::string &line,
    const std::size_t &lineNumber):ParsingException{filename, line, lineNumber},
    _first{first}
{
    _message   = "Pin number should be a positive integer";
    _errorCode = "[Pin-Number-Error]";

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