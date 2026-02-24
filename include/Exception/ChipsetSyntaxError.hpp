/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetSyntaxError
*/

#ifndef NANOTEKSPICE_CHIPSETSYNTAXERROR_HPP
#define NANOTEKSPICE_CHIPSETSYNTAXERROR_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class ChipsetSyntaxError: public ParsingException {
public:
    explicit ChipsetSyntaxError(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_CHIPSETSYNTAXERROR_HPP
