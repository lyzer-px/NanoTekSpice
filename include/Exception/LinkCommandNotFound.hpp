/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkCommandNotFound
*/

#ifndef NANOTEKSPICE_LINKCOMMANDNOTFOUND_HPP
#define NANOTEKSPICE_LINKCOMMANDNOTFOUND_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class LinkCommandNotFound: public ParsingException {
public:
    explicit LinkCommandNotFound(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_LINKCOMMANDNOTFOUND_HPP
