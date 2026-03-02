/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ChipsetCommandNotFound
*/

#ifndef NANOTEKSPICE_CHIPSETCOMMANDNOTFOUND_HPP
#define NANOTEKSPICE_CHIPSETCOMMANDNOTFOUND_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class ChipsetCommandNotFound: public ParsingException {
public:
    explicit ChipsetCommandNotFound(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_CHIPSETCOMMANDNOTFOUND_HPP
