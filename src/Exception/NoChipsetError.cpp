/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** NoChipsetError
*/

#include "../../include/Exception/NoChipsetError.hpp"

#include <sstream>

namespace nts {
namespace error {
NoChipsetError::NoChipsetError(const std::string &fileName,
    const std::string &line, const std::size_t lineNumber):
    ParsingException(fileName, line, lineNumber)
{
    _message = "No chipset registered to set links";
    _errorCode = "[No-chipset-Error]";

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