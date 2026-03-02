/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetAlreadyDefinedError
*/

#ifndef NANOTEKSPICE_CHIPSETALREADYDEFINEDERROR_HPP
#define NANOTEKSPICE_CHIPSETALREADYDEFINEDERROR_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class ChipsetAlreadyDefinedError: public ParsingException {
public:
    explicit ChipsetAlreadyDefinedError(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_CHIPSETALREADYDEFINEDERROR_HPP
