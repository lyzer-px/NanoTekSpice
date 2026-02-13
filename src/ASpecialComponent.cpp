/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ASpecialComponent
*/

#include "ASpecialComponent.hpp"

namespace nts {
ASpecialComponent::ASpecialComponent(std::string name): AComponent(
    std::move(name))
{
    _numberOfPin = 1;
}
} // nts
