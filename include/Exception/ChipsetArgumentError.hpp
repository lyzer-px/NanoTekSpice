/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetArgumentError
*/

#ifndef NANOTEKSPICE_CHIPSETARGUMENTERROR_HPP
#define NANOTEKSPICE_CHIPSETARGUMENTERROR_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class ChipsetArgumentError: public ParsingException {
public:
    explicit ChipsetArgumentError(const bool &tooMuch,
        const std::string &filename, const std::string &line,
        const std::size_t &lineNumber);

private:
    bool _tooMuch;
};
} // error
} // nts

#endif //NANOTEKSPICE_CHIPSETARGUMENTERROR_HPP
