/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** NoChipsetError
*/

#ifndef NANOTEKSPICE_NOCHIPSETERROR_HPP
#define NANOTEKSPICE_NOCHIPSETERROR_HPP
#include "ParsingException.hpp"

namespace nts {
namespace error {
class NoChipsetError: public ParsingException {
public:
    explicit NoChipsetError(const std::string &fileName,
        const std::string &line, const std::size_t lineNumber);
};
} // error
} // nts

#endif //NANOTEKSPICE_NOCHIPSETERROR_HPP
