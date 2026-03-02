/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** UnknowChipsetType
*/

#ifndef NANOTEKSPICE_UNKNOWCHIPSETTYPE_HPP
#define NANOTEKSPICE_UNKNOWCHIPSETTYPE_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class UnknowChipsetType: public ParsingException {
public:
    explicit UnknowChipsetType(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_UNKNOWCHIPSETTYPE_HPP
