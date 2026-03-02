/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** PinNumberIsInteger
*/

#ifndef NANOTEKSPICE_PINNUMBERISINTEGER_HPP
#define NANOTEKSPICE_PINNUMBERISINTEGER_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class PinNumberIsInteger: public ParsingException {
public:
    explicit PinNumberIsInteger(const bool &first, const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);

private:
    bool _first;
};
} // error
} // nts

#endif //NANOTEKSPICE_PINNUMBERISINTEGER_HPP
