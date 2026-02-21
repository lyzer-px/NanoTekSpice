/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ACompositeComponent
*/

#ifndef NANOTEKSPICE_ACOMPOSITECOMPONENT_HPP
#define NANOTEKSPICE_ACOMPOSITECOMPONENT_HPP
#include <map>
#include <memory>

#include "../../../include/components/AComponent.hpp"

namespace nts {
class IComponent;

class ACompositeComponent: public AComponent {
public:
    explicit ACompositeComponent(std::string name);

    Tristate compute(const std::size_t &pin) override;

    void setLink(const std::size_t &pin, IComponent &other,
        const std::size_t &otherPin) override;

    virtual void registerInternComponentsPins();
    virtual void setPinsType();

protected:
    std::vector<std::unique_ptr<IComponent>> _components;
    std::unordered_map<std::size_t, std::pair<IComponent *, std::size_t>>
        _inputPins;
};

} // namespace nts

#endif // NANOTEKSPICE_ACOMPOSITECOMPONENT_HPP
