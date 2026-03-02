/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** LinkSyntaxError
*/

#ifndef NANOTEKSPICE_LINKSYNTAXERROR_HPP
#define NANOTEKSPICE_LINKSYNTAXERROR_HPP

#include "ParsingException.hpp"

namespace nts {
namespace error {
class LinkSyntaxError: public ParsingException {
public:
    explicit LinkSyntaxError(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_LINKSYNTAXERROR_HPP
