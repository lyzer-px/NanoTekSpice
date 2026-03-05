/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ParsingTooManyTokens
*/

#include "../../include/Exception/ParsingTooManyTokens.hpp"

#include <sstream>

namespace nts {
namespace error {
ParsingTooManyTokens::ParsingTooManyTokens(const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    ParsingException{filename, line, lineNumber}
{
    _message = "Too many tokens to split";
    _errorCode = "[Too-many-tokens]";

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
