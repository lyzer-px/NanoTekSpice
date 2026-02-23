
/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourNor
*/

#include "components/composite/FourNor.hpp"

#include "components/elementary/Nor.hpp"

namespace nts {
FourNor::FourNor(std::string name): ACompositeComponent{std::move(name)}
{
    _type = FOUR_NOR_TYPE;

    for (std::size_t i = 0; i < 4; ++i)
        _components.push_back(
            std::make_unique<Nor>("or_" + std::to_string(i + 1)));

    ACompositeComponent::registerInternComponentsPins();

    ACompositeComponent::setPinsType();
}
std::unique_ptr<IComponent> FourNor::create(std::string name)
{
    return std::make_unique<FourNor>(std::move(name));
}
} // namespace nts
