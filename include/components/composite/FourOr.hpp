/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourOr
*/

#ifndef NANOTEKSPICE_FOUROR_HPP
#define NANOTEKSPICE_FOUROR_HPP
#include "ACompositeComponent.hpp"

namespace nts {

class FourOr: public ACompositeComponent {
public:
    explicit FourOr(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};

} // namespace nts

#endif // NANOTEKSPICE_FOUROR_HPP
