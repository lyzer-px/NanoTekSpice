/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AComponent
*/

#ifndef NANOTEKSPICE_ACOMPONENT_HPP
#define NANOTEKSPICE_ACOMPONENT_HPP

#include <cstdint>
#include <string>
#include <unordered_map>

#include "IComponent.hpp"

namespace nts {
enum class PinType: std::uint8_t {
    INPUT,
    OUTPUT
};

struct Pin {
    Pin();

    explicit Pin(const PinType &pinType, IComponent *component,
        const std::size_t &pinNumber);

    PinType type;
    IComponent *linkedComponent;
    std::size_t pin;
};

class AComponent: public IComponent {
public:
    explicit AComponent(std::string name);

    void setLink(const std::size_t &pin, IComponent &other,
        const std::size_t &otherPin) override;;

    void simulate(const std::size_t &tick) override;

    static PinType getPinType(const std::size_t &pin, IComponent &component);

    std::string getName() override;

protected:
    std::string _type;
    std::string _name;
    std::size_t _numberOfPin;
    std::size_t _tick;
    std::pmr::unordered_map<std::size_t, Pin> _pins;
};
} // nts

std::ostream &operator<<(std::ostream &outStream, const nts::Tristate &state);

#endif //NANOTEKSPICE_ACOMPONENT_HPP
