/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ParsingError
*/

#ifndef NANOTEKSPICE_PARSINGERROR_HPP
#define NANOTEKSPICE_PARSINGERROR_HPP

#include <exception>
#include <string>

namespace nts {
namespace error {
class ParsingException: public std::exception {
public:
    explicit ParsingException(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);

    const char *what() const noexcept override;

    void description() const noexcept;

    static std::size_t getUnderlineSize(const std::string &str);

protected:
    std::string _message;
    std::string _filename;
    std::string _line;
    std::size_t _lineNumber;
    std::string _errorCode;
    std::string _what;
    std::string _errorDescription;
    std::size_t _cursorPosition = -1;
    std::size_t _underlineSize  = 0;
};
} // namespace error
} // namespace nts

#endif // NANOTEKSPICE_PARSINGERROR_HPP
