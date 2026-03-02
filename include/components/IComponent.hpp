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
constexpr std::string INPUT_TYPE        = "input";
constexpr std::string OUTPUT_TYPE       = "output";
constexpr std::string TRUE_TYPE         = "true";
constexpr std::string FALSE_TYPE        = "false";
constexpr std::string CLOCK_TYPE        = "clock";
constexpr std::string AND_TYPE          = "and";
constexpr std::string NAND_TYPE         = "nand";
constexpr std::string OR_TYPE           = "or";
constexpr std::string XOR_TYPE          = "xor";
constexpr std::string NOR_TYPE          = "nor";
constexpr std::string XNOR_TYPE         = "xnor";
constexpr std::string NOT_TYPE          = "not";
constexpr std::string FOUR_AND_TYPE     = "4081";
constexpr std::string FOUR_OR_TYPE      = "4071";
constexpr std::string SIX_INVERTER_TYPE = "4069";
constexpr std::string FOUR_XOR_TYPE     = "4030";
constexpr std::string FOUR_NAND_TYPE    = "4011";
constexpr std::string FOUR_NOR_TYPE     = "4001";
constexpr std::string FULL_ADDER_TYPE   = "full_adder";

enum Tristate: std::uint8_t {
    FALSE     = 0U,
    TRUE      = 1U,
    UNDEFINED = 2U,
    ERROR
};

class IComponent {
public :
    virtual ~IComponent() = default;

    virtual void simulate(const std::size_t &tick) = 0;

    virtual Tristate compute(const std::size_t &pin) = 0;

    virtual void setLink(const std::size_t &pin, IComponent &other,
        const std::size_t &otherPin) = 0;

    virtual void setState(const Tristate &state) = 0;

    virtual std::string getName() const noexcept = 0;
};
}

#endif // ICOMPONENT_HPP
