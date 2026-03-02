/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourXor
*/

#include "components/composite/FourXor.hpp"

#include "components/elementary/Xor.hpp"

namespace nts {
FourXor::FourXor(std::string name): ACompositeComponent{std::move(name)}
{
    _type = FOUR_XOR_TYPE;

    for (std::size_t i = 0; i < 4; ++i)
        _components.push_back(
            std::make_unique<Xor>("xor_" + std::to_string(i + 1)));

    ACompositeComponent::registerInternComponentsPins();

    ACompositeComponent::setPinsType();
}
std::unique_ptr<IComponent> FourXor::create(std::string name)
{
    return std::make_unique<FourXor>(std::move(name));
}
} // namespace nts
