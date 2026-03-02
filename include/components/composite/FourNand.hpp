
/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourNand
*/

#ifndef NANOTEKSPICE_FOURNAND_HPP
#define NANOTEKSPICE_FOURNAND_HPP
#include "ACompositeComponent.hpp"

namespace nts {

class FourNand: public ACompositeComponent {
public:
    explicit FourNand(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};

} // namespace nts

#endif // NANOTEKSPICE_FOURNAND_HPP
