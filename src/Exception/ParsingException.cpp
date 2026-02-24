/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ParsingError
*/

#include <iostream>
#include <sstream>

#include "../../include/Exception/ParsingException.hpp"
#include "../../include/constants.hpp"
#include "../Utils/StringUtils.hpp"

namespace nts {
namespace error {
ParsingException::ParsingException(const std::string &filename,
    const std::string &line, const std::size_t &lineNumber):
    _filename{filename}, _line{line}, _lineNumber{lineNumber}
{
    if (_line[line.size() - 1] == '\r')
        _line.erase(line.size() - 1);
}

const char *ParsingException::what() const noexcept
{
    return "Nope";
}

void ParsingException::description() const noexcept
{
    std::cerr << _filename << ":" << _lineNumber << ": " << RED << "error: " <<
        RESET << _message << " " << RED << _errorCode << RESET << std::endl;
    std::cerr << _errorDescription << std::endl;

    std::stringstream stream;

    stream << "  " << utils::StringUtils::spaces(
            std::to_string(_lineNumber).size()) << " | " <<
        utils::StringUtils::spaces(_cursorPosition)
        << GREEN << "^" << utils::StringUtils::fillChars(_underlineSize,
            '~') << RESET;

    std::cerr << stream.str() << std::endl;
}

std::size_t ParsingException::getUnderlineSize(const std::string &str)
{
    std::size_t counter = 0;

    while (str[counter] == ' ' && counter != str.size() - 1)
        counter++;

    std::size_t result = str.substr(counter).size();

    if (result == 1)
        return --result;

    return  result - 1;
}
} // namespace error
} // namespace nts
