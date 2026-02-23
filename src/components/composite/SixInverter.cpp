/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** SixInverter
*/

#include "components/composite/SixInverter.hpp"

#include "components/elementary/Not.hpp"

namespace nts {

void SixInverter::setPinsType()
{
    for (const auto &pin: {1, 3, 5, 7, 9, 11}) {
        _pins[pin] = Pin(PinType::INPUT); 
    }
    for (const auto &pin: {2, 4, 6, 8, 10, 12}) {
        _pins[pin] = Pin(PinType::OUTPUT);
    }
    _pins[13] = Pin(PinType::POWER);
}

void SixInverter::registerInternComponentsPins()
{
   _inputPins[1] = std::pair{_components[0].get(), 1}; 
   _inputPins[2] = std::pair{_components[1].get(), 2}; 
   _inputPins[3] = std::pair{_components[2].get(), 1}; 
   _inputPins[4] = std::pair{_components[3].get(), 2}; 
   _inputPins[5] = std::pair{_components[4].get(), 1}; 
   _inputPins[6] = std::pair{_components[5].get(), 2}; 
   _inputPins[7] = std::pair{_components[6].get(), 1}; 
   _inputPins[13]  = std::pair{nullptr, 0};
}

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
