/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetArgumentError
*/

#include "../../include/Exception/ChipsetArgumentError.hpp"

#include <iostream>
#include <sstream>

#include "../../include/constants.hpp"
#include "../Utils/StringUtils.hpp"

namespace nts {
namespace error {
ChipsetArgumentError::ChipsetArgumentError(const bool &tooMuch,
    const std::string &filename, const std::string &line,
    const std::size_t &lineNumber): ParsingException
    {filename, line, lineNumber},
    _tooMuch{tooMuch}
{
    if (_tooMuch)
        _message = "Too much argument to define chipset";
    else
        _message = "Chipset name not provided";
    _errorCode = "[Chipset-Argument-Error]";

    std::stringstream stream;

    stream << "  " << _lineNumber << " | " << _line;
    _errorDescription = stream.str();

    stream.str(_line);
    std::string temp;
    stream >> temp;
    if (tooMuch)
        stream >> temp;
    std::getline(stream, temp);
    _cursorPosition = _line.find(temp) +
        utils::StringUtils::beginSpacesCount(temp);
    stream >> temp;
    _underlineSize = getUnderlineSize(temp);
}
} // error
} // nts
