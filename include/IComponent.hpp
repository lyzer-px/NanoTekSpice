/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <cstdint>
#include <string>

namespace nts {
enum Tristate: std::uint8_t {
    FALSE     = 0U,
    TRUE      = 1U,
    UNDEFINED = 2U
};

class IComponent {
public :
    virtual ~IComponent() = default;

    virtual void simulate(const std::size_t &tick) = 0;

    virtual Tristate compute(const std::size_t &pin) = 0;

    virtual void setLink(const std::size_t &pin, IComponent &other,
        const std::size_t &otherPin) = 0;

    virtual std::string getName() const noexcept = 0;
};
}

#endif // ICOMPONENT_HPP
