/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetAlreadyDefinedError
*/

#include <sstream>

#include "../../include/Exception/ChipsetAlreadyDefinedError.hpp"

#include <iostream>

#include "../../include/constants.hpp"
#include "../Utils/StringUtils.hpp"

namespace nts {
namespace error {
ChipsetAlreadyDefinedError::ChipsetAlreadyDefinedError(
    const std::string &filename, const std::string &line,
    const std::size_t &lineNumber): ParsingException{filename, line, lineNumber}
{
    _message   = "Chipset name already defined above";
    _errorCode = "[Chipset-Name-Error]";

    std::stringstream stream;
    stream << "  " << _lineNumber << " | " << _line;

    _errorDescription = stream.str();

    stream.str(_line);
    std::string temp;
    stream >> temp;
    std::getline(stream, temp);
    _cursorPosition = _line.find(temp) +
        utils::StringUtils::beginSpacesCount(temp);
    stream >> temp;
    _underlineSize = getUnderlineSize(temp);
}
} // error
} // nts
