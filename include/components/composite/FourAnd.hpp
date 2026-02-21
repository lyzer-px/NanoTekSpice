/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourAnd
*/

#ifndef NANOTEKSPICE_FOURAND_HPP
#define NANOTEKSPICE_FOURAND_HPP
#include "ACompositeComponent.hpp"

namespace nts {

class FourAnd: public ACompositeComponent {
public:
    explicit FourAnd(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};

} // namespace nts

#endif // NANOTEKSPICE_FOURAND_HPP
