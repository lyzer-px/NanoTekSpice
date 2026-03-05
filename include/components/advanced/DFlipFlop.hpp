/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** DFlipFlop
*/

#ifndef NANOTEKSPICE_DFLIPFLOP_HPP
#define NANOTEKSPICE_DFLIPFLOP_HPP

#include "components/composite/ACompositeComponent.hpp"

namespace nts {
class DFlipFlop: public ACompositeComponent {
public:
    explicit DFlipFlop(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);

private:
    void registerInternComponentsPins() override;

    void setPinsType() override;
};
} // nts

#endif //NANOTEKSPICE_DFLIPFLOP_HPP
