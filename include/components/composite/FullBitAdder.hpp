/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FullBitAdder
*/

#ifndef NANOTEKSPICE_FULLBITADDER_HPP
#define NANOTEKSPICE_FULLBITADDER_HPP
#include "ACompositeComponent.hpp"

namespace nts {
class FullBitAdder: public ACompositeComponent {
public:
    explicit FullBitAdder(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);

private:
    void registerInternComponentsPins() override;

    void setPinsType() override;
};
} // nts

#endif //NANOTEKSPICE_FULLBITADDER_HPP
