/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** SixInverter
*/

#ifndef NANOTEKSPICE_SIXINVERTER_HPP
#define NANOTEKSPICE_SIXINVERTER_HPP
#include "ACompositeComponent.hpp"

namespace nts {

class SixInverter: public ACompositeComponent {
public:
    explicit SixInverter(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};

} // namespace nts

#endif // NANOTEKSPICE_FOURNAND_HPP
