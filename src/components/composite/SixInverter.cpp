/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** SixInverter
*/

#include "components/composite/SixInverter.hpp"

#include "components/elementary/Not.hpp"

namespace nts {
SixInverter::SixInverter(std::string name): ACompositeComponent{std::move(name)}
{
    _type = FOUR_NAND_TYPE;

    for (std::size_t i = 0; i < 6; ++i)
        _components.push_back(
            std::make_unique<Not>("not_" + std::to_string(i + 1)));

    ACompositeComponent::registerInternComponentsPins();

    ACompositeComponent::setPinsType();
}
std::unique_ptr<IComponent> SixInverter::create(std::string name)
{
    return std::make_unique<SixInverter>(std::move(name));
}
} // namespace nts
