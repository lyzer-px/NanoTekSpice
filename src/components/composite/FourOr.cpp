/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourOr
*/

#include "components/composite/FourOr.hpp"

#include "components/elementary/Or.hpp"

namespace nts {
FourOr::FourOr(std::string name): ACompositeComponent{std::move(name)}
{
    _type = FOUR_OR_TYPE;

    for (std::size_t i = 0; i < 4; ++i)
        _components.push_back(
            std::make_unique<Or>("or_" + std::to_string(i + 1)));

    ACompositeComponent::registerInternComponentsPins();

    ACompositeComponent::setPinsType();
}
std::unique_ptr<IComponent> FourOr::create(std::string name)
{
    return std::make_unique<FourOr>(std::move(name));
}
} // namespace nts
