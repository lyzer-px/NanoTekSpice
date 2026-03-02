/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkDefinitionSyntaxError
*/

#ifndef NANOTEKSPICE_LINKDEFINITIONSYNTAXERROR_HPP
#define NANOTEKSPICE_LINKDEFINITIONSYNTAXERROR_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class LinkDefinitionSyntaxError: public ParsingException {
public:
    explicit LinkDefinitionSyntaxError(const bool first,
        const std::string &filename, const std::string &line,
        const std::size_t &lineNumber);

private:
    bool _first;
};
} // error
} // nts

#endif //NANOTEKSPICE_LINKDEFINITIONSYNTAXERROR_HPP
