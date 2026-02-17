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
constexpr std::string INPUT_TYPE  = "input";
constexpr std::string OUTPUT_TYPE = "output";
constexpr std::string TRUE_TYPE   = "true";
constexpr std::string FALSE_TYPE  = "false";
constexpr std::string CLOCK_TYPE  = "clock";

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
