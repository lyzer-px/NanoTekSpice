/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** HalfAdder
*/

#ifndef NANOTEKSPICE_HALFADDER_HPP
#define NANOTEKSPICE_HALFADDER_HPP
#include "../composite/ACompositeComponent.hpp"

namespace nts {
class HalfAdder: public ACompositeComponent {
public:
    explicit HalfAdder(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);

private:
    void registerInternComponentsPins() override;

    void setPinsType() override;
};
} // nts

#endif //NANOTEKSPICE_HALFADDER_HPP
