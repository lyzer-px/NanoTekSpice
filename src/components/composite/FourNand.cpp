/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourNand
*/

#include "components/composite/FourNand.hpp"

#include "components/elementary/Nand.hpp"

namespace nts {
FourNand::FourNand(std::string name): ACompositeComponent{std::move(name)}
{
    _type = FOUR_NAND_TYPE;

    for (std::size_t i = 0; i < 4; ++i)
        _components.push_back(
            std::make_unique<Nand>("nand_" + std::to_string(i + 1)));

    ACompositeComponent::registerInternComponentsPins();

    ACompositeComponent::setPinsType();
}
std::unique_ptr<IComponent> FourNand::create(std::string name)
{
    return std::make_unique<FourNand>(std::move(name));
}
} // namespace nts
