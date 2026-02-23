/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourNor
*/

#ifndef NANOTEKSPICE_FOURNOR_HPP
#define NANOTEKSPICE_FOURNOR_HPP
#include "ACompositeComponent.hpp"

namespace nts {

class FourNor: public ACompositeComponent {
public:
    explicit FourNor(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};

} // namespace nts

#endif // NANOTEKSPICE_FOURNOR_HPP

