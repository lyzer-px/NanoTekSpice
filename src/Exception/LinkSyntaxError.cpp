/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkSyntaxError
*/

#include "../../include/Exception/LinkSyntaxError.hpp"

#include <sstream>

namespace nts {
namespace error {
LinkSyntaxError::LinkSyntaxError(const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    ParsingException{filename, line, lineNumber}
{
    _message = std::string("Syntax error in link definition.") +
        " Missing the two terms for link definition";
    _errorCode = "[Link-Syntax-Error]";

    std::stringstream stream;
    stream << "  " << _lineNumber << " | " << _line;

    _errorDescription = stream.str();

    stream.str(_line);
    std::string temp;
    stream >> temp;

    _cursorPosition = _line.find(temp);
    _underlineSize  = getUnderlineSize(_line);
}
} // error
} // nts
