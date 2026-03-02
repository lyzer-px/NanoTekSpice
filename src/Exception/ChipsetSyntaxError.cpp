/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetSyntaxError
*/

#include "../../include/Exception/ChipsetSyntaxError.hpp"

namespace nts {
namespace error {
ChipsetSyntaxError::ChipsetSyntaxError(const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    ParsingException{filename, line, lineNumber}
{
    _message = "Error in chipset definition syntax";
    _errorCode = "[Chipset-Syntax-Error]";
}
} // error
} // nts