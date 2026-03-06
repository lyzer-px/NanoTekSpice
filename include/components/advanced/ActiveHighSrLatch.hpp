/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ActiveHighSrLatch
*/

#ifndef NANOTEKSPICE_ACTIVEHIGHSRLATCH_HPP
#define NANOTEKSPICE_ACTIVEHIGHSRLATCH_HPP
#include "../composite/ACompositeComponent.hpp"

namespace nts {
class ActiveHighSRLatch: public ACompositeComponent {
public:
    explicit ActiveHighSRLatch(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);

private:
    void registerInternComponentsPins() override;

    void setPinsType() override;
};
} // nts

#endif //NANOTEKSPICE_ACTIVEHIGHSRLATCH_HPP
