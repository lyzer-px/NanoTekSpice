/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** UnknownChipsetType
*/

#ifndef NANOTEKSPICE_UNKNOWNCHIPSETTYPE_HPP
#define NANOTEKSPICE_UNKNOWNCHIPSETTYPE_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class UnknownChipsetType: public ParsingException {
public:
    explicit UnknownChipsetType(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_UNKNOWNCHIPSETTYPE_HPP
