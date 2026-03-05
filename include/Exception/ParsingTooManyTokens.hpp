/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ParsingTooManyTokens
*/

#ifndef NANOTEKSPICE_PARSINGTOOMANYTOKENS_HPP
#define NANOTEKSPICE_PARSINGTOOMANYTOKENS_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class ParsingTooManyTokens: public ParsingException {
public:
    explicit ParsingTooManyTokens(const std::string &filename,
        const std::string &line, const std::size_t &lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_PARSINGTOOMANYTOKENS_HPP
