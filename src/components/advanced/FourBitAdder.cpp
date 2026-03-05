/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FourBitAdder
*/

#include "../../../include/components/advanced/FourBitAdder.hpp"
#include "../../../include/components/advanced/FullBitAdder.hpp"

namespace nts {
FourBitAdder::FourBitAdder(std::string name): ACompositeComponent{
    std::move(name)}
{
    _type        = FOUR_BIT_ADDER_TYPE;
    _numberOfPin = 16;

    for (std::size_t i = 0; i < 4; ++i)
        _components.push_back(
            std::make_unique<FullBitAdder>("adder_" + std::to_string(i + 1)));

    FourBitAdder::registerInternComponentsPins();

    FourBitAdder::setPinsType();
}

std::unique_ptr<IComponent> FourBitAdder::create(std::string name)
{
    return std::make_unique<FourBitAdder>(name);
}

void FourBitAdder::registerInternComponentsPins()
{
    _components[0]->setLink(3, *_components[1], 5);
    _components[1]->setLink(3, *_components[2], 5);
    _components[2]->setLink(3, *_components[3], 5);

    _internalPins[1]  = {std::pair{_components[0].get(), 2}};
    _internalPins[2]  = {std::pair{_components[1].get(), 1}};
    _internalPins[3]  = {std::pair{_components[1].get(), 2}};
    _internalPins[4]  = {std::pair{_components[2].get(), 1}};
    _internalPins[5]  = {std::pair{_components[2].get(), 2}};
    _internalPins[6]  = {std::pair{_components[3].get(), 1}};
    _internalPins[7]  = {std::pair{_components[3].get(), 2}};
    _internalPins[8]  = {};
    _internalPins[9]  = {std::pair{_components[3].get(), 3}};
    _internalPins[10] = {std::pair{_components[3].get(), 4}};
    _internalPins[11] = {std::pair{_components[2].get(), 4}};
    _internalPins[12] = {std::pair{_components[1].get(), 4}};
    _internalPins[13] = {std::pair{_components[0].get(), 4}};
    _internalPins[14] = {std::pair{_components[0].get(), 5}};
    _internalPins[15] = {std::pair{_components[0].get(), 1}};
    _internalPins[16] = {};
}

void FourBitAdder::setPinsType()
{
    for (const auto &pin: {1, 2, 3, 4, 5, 6, 7, 9, 15})
        _pins[pin] = Pin{PinType::INPUT};

    for (const auto &pin: {10, 11, 12, 13, 14})
        _pins[pin] = Pin{PinType::OUTPUT};

    _pins[8] = _pins[16] = Pin{PinType::POWER};
}
} // nts
