/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkDefinitionSyntaxError
*/

#include "../../include/Exception/LinkDefinitionSyntaxError.hpp"

#include <sstream>

#include "../Utils/StringUtils.hpp"

namespace nts {
namespace error {
LinkDefinitionSyntaxError::LinkDefinitionSyntaxError(const bool first,
    const std::string &filename, const std::string &line,
    const std::size_t &lineNumber): ParsingException
    {filename, line, lineNumber},
    _first{first}
{
    _message   = "Syntax error in link definition";
    _errorCode = "[Link-Definition-Syntax-Error]";

    std::stringstream stream;

    stream << "  " << _lineNumber << " | " << _line;
    _errorDescription = stream.str();

    stream.str(_line);
    std::string temp;
    stream >> temp;
    // if (!_first)
    //     stream >> temp;
    // std::getline(stream, temp);
    if (_first)
        _cursorPosition = _line.find(temp) +
            utils::StringUtils::beginSpacesCount(temp);
    else {
        std::getline(stream, temp);
        _cursorPosition = _line.find(temp) +
            utils::StringUtils::beginSpacesCount(temp);
    }
    // stream >> temp;
    _underlineSize = getUnderlineSize(temp);
}
} // error
} // nts
