/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** BadFileExtentionException
*/

#include "../../include/Exception/BadFileExtensionException.hpp"

namespace nts {
namespace error {
const char * BadFileExtensionException::what() const noexcept
{
    return "Bad file extension";
}
} // error
} // nts