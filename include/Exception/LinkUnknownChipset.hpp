/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkUnknownChipset
*/

#ifndef NANOTEKSPICE_LINKUNKNOWNCHIPSET_HPP
#define NANOTEKSPICE_LINKUNKNOWNCHIPSET_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class LinkUnknownChipset: public ParsingException {
public:
    explicit LinkUnknownChipset(const bool &first, const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);

private:
    bool _first;
};
} // error
} // nts

#endif //NANOTEKSPICE_LINKUNKNOWNCHIPSET_HPP
