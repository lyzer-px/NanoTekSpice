/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** SixInverter
*/

#include "../../../include/components/composite/SixInverter.hpp"

#include "../../../include/components/IComponent.hpp"
#include "../../../include/components/elementary/Not.hpp"

namespace nts {

SixInverter::SixInverter(std::string name): ACompositeComponent{std::move(name)}
{
    _type = SIX_INVERTER_TYPE;

    for (std::size_t i = 0; i < 6; ++i)
        _components.push_back(
            std::make_unique<Not>("not_" + std::to_string(i + 1)));
    this->SixInverter::registerInternComponentsPins();
    this->SixInverter::setPinsType();
}

std::unique_ptr<IComponent> SixInverter::create(std::string name)
{
    return std::make_unique<SixInverter>(std::move(name));
}

void SixInverter::registerInternComponentsPins()
{
    _internalPins[1]  = {std::pair{_components[0].get(), 1}};
    _internalPins[2]  = {std::pair{_components[0].get(), 2}};
    _internalPins[3]  = {std::pair{_components[1].get(), 1}};
    _internalPins[4]  = {std::pair{_components[1].get(), 2}};
    _internalPins[5]  = {std::pair{_components[2].get(), 1}};
    _internalPins[6]  = {std::pair{_components[2].get(), 2}};
    _internalPins[7]  = {};
    _internalPins[8]  = {std::pair{_components[3].get(), 2}};
    _internalPins[9]  = {std::pair{_components[3].get(), 1}};
    _internalPins[10] = {std::pair{_components[4].get(), 2}};
    _internalPins[11] = {std::pair{_components[4].get(), 1}};
    _internalPins[12] = {std::pair{_components[5].get(), 2}};
    _internalPins[13] = {std::pair{_components[5].get(), 1}};
    _internalPins[14] = {};
}

void SixInverter::setPinsType()
{
    for (const auto &pin: {1, 3, 5, 9, 11, 13}) {
        _pins[pin] = Pin(PinType::INPUT);
    }
    for (const auto &pin: {2, 4, 6, 8, 10, 12}) {
        _pins[pin] = Pin(PinType::OUTPUT);
    }
    _pins[7]  = Pin(PinType::POWER);
    _pins[14] = Pin(PinType::POWER);
}
} // namespace nts
