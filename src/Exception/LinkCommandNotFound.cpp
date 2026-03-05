/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkCommandNotFound
*/

#include "../../include/Exception/LinkCommandNotFound.hpp"

#include <sstream>

namespace nts {
namespace error {
LinkCommandNotFound::LinkCommandNotFound(const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    ParsingException{filename, line, lineNumber}
{
    _message = "Link command has no content";
    _errorCode = "[Link-Command-No-Content]";

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
