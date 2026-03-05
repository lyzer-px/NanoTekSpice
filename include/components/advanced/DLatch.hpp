/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** DLatch
*/

#ifndef NANOTEKSPICE_DLATCH_HPP
#define NANOTEKSPICE_DLATCH_HPP
#include "../composite/ACompositeComponent.hpp"

namespace nts {
class DLatch: public ACompositeComponent {
public:
    explicit DLatch(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);

private:
    void registerInternComponentsPins() override;

    void setPinsType() override;
};
} // nts

#endif //NANOTEKSPICE_DLATCH_HPP
