/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkNoPinNumber
*/

#ifndef NANOTEKSPICE_LINKNOPINNUMBER_HPP
#define NANOTEKSPICE_LINKNOPINNUMBER_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class LinkNoPinNumber: public ParsingException {
public:
    explicit LinkNoPinNumber(const bool &first, const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);

private:
    bool _first;
};
} // error
} // nts

#endif //NANOTEKSPICE_LINKNOPINNUMBER_HPP
