/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** UnknownChipsetType
*/

#include "Exception/UnknownChipsetType.hpp"

#include <iostream>
#include <sstream>

namespace nts {
namespace error {
UnknownChipsetType::UnknownChipsetType(const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    ParsingException{filename, line, lineNumber}
{
    _message = "Unknown Chipset type in chipset definition";
    _errorCode = "[Unknown-Chipset-Type]";

    std::stringstream stream;
    stream << "  " << _lineNumber << " | " << _line;

    _errorDescription = stream.str();

    stream.str(_line);
    std::string temp;
    stream >> temp;
    _cursorPosition = _line.find(temp);
    _underlineSize = getUnderlineSize(temp);
}
} // error
} // nts
