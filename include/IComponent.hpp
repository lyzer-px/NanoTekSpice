/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP
#include <cstddef>

namespace nts {
enum Tristate {
    Undefined = (-true),
    True      = true,
    False     = false
};

class IComponent {
public :
    virtual ~IComponent() = default;

    virtual void simulate(std::size_t tick) = 0;

    virtual Tristate compute(std::size_t pin) = 0;

    virtual void setLink(std::size_t pin, IComponent &other,
        std::size_t otherPin) = 0;
};
}

#endif // ICOMPONENT_HPP
