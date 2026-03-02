/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** BadFileExtentionException
*/

#ifndef NANOTEKSPICE_BADFILEEXTENTIONEXCEPTION_HPP
#define NANOTEKSPICE_BADFILEEXTENTIONEXCEPTION_HPP

#include <exception>

namespace nts {
namespace error {
class BadFileExtensionException: public std::exception {
public:
    const char *what() const noexcept override;
};
} // error
} // nts

#endif //NANOTEKSPICE_BADFILEEXTENTIONEXCEPTION_HPP