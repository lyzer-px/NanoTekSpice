/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourBitAdder
*/

#ifndef NANOTEKSPICE_FOURBITADDER_HPP
#define NANOTEKSPICE_FOURBITADDER_HPP
#include "../composite/ACompositeComponent.hpp"

namespace nts {
class FourBitAdder: public ACompositeComponent {
public:
    explicit FourBitAdder(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);

private:
    void registerInternComponentsPins() override;

    void setPinsType() override;
};
} // nts

#endif //NANOTEKSPICE_FOURBITADDER_HPP
