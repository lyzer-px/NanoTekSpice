/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourAnd
*/

#include "components/composite/FourAnd.hpp"

#include "components/elementary/And.hpp"

namespace nts {
FourAnd::FourAnd(std::string name): ACompositeComponent{std::move(name)}
{
    _type = FOUR_AND_TYPE;

    for (std::size_t i = 0; i < 4; ++i)
        _components.push_back(
            std::make_unique<And>("and_" + std::to_string(i + 1)));

    ACompositeComponent::registerInternComponentsPins();

    ACompositeComponent::setPinsType();
}
std::unique_ptr<IComponent> FourAnd::create(std::string name)
{
    return std::make_unique<FourAnd>(std::move(name));
}
} // namespace nts
