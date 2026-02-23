/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourXor
*/

#ifndef NANOTEKSPICE_FOURXOR_HPP
#define NANOTEKSPICE_FOURXOR_HPP
#include "ACompositeComponent.hpp"

namespace nts {

class FourXor: public ACompositeComponent {
public:
    explicit FourXor(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};

} // namespace nts

#endif // NANOTEKSPICE_FOURXOR_HPP
