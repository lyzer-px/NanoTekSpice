/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetCommandNotFound
*/

#include "../../include/Exception/ChipsetCommandNotFound.hpp"

#include <sstream>

namespace nts {
namespace error {
ChipsetCommandNotFound::ChipsetCommandNotFound(const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    ParsingException{filename, line, lineNumber}
{
    _message = "Chipset command not found";
    _errorCode = "[Chipset-Command-Not-Found]";

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